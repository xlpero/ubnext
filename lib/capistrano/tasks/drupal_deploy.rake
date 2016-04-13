# Load default values the capistrano 3.x way.
# See https://github.com/capistrano/capistrano/pull/605
# TODO: Require template plugin, how?
namespace :load do
  task :defaults do
    set :app_path, 'web' #??
    set :drupal_data_permit_write, true
    set :templating_paths, fetch(:templating_paths) << "lib/capistrano/templates"
  end
end

# Settable?
# :locale_data_path ?
# Data directory for locally stored data
file 'data' do
  mkdir('data')
end

#?
#file 'data/database.sql' do
  #invoke shit
#end

# Install drush
namespace :drush do
  desc "Install Drush"
  task :install do
    on release_roles :app do
      within shared_path do
        execute :composer, 'require drush/drush:7.*'
      end
    end
  end
end

namespace :drupal do

  #Is this kosher?
  def data_permit_write
    puts "Writing data not permitted for stage '#{fetch(:stage)}'." unless fetch(:drupal_data_permit_write)
    fetch(:drupal_data_permit_write)
  end

  desc "Export data"
  task :'export-data' do
    invoke 'drupal:export-files'
    invoke 'drupal:export-database'
  end

  desc "Import data"
  task :'import-data' do
    next unless data_permit_write
    invoke 'drupal:import-files'
    invoke 'drupal:import-database'
  end

  desc "Export files"
  task :'export-files' do
    invoke 'drupal:stash-files'
    invoke 'drupal:stash-files:download'
  end

  desc "Import files"
  task :'import-files' do
    next unless data_permit_write
    invoke 'drupal:stash-files:upload'
    invoke 'drupal:stash-files:apply'
  end

  desc "Export database"
  task :'export-database' do
    invoke 'drupal:stash-database'
    invoke 'drupal:stash-database:download'
  end

  desc "Import database"
  task :'import-database' do
    next unless data_permit_write
    invoke 'drupal:stash-database:upload'
    invoke 'drupal:stash-database:apply'
  end

  namespace :'stash-files' do
    desc "Remove stashed files"
    task :remove do
      on release_roles :app do
        next unless test("[ -d #{current_path.join('files')} ]")
        execute :rm, '-R', current_path.join('files')
      end
    end

    desc "List stashed files"
    task :list do
      on release_roles :app do
        next unless test("[ -d #{current_path.join('files')} ]")
        puts capture(:find, current_path.join('files'))
      end
    end

    desc "List tree of stashed files"
    task :tree do
      on release_roles :app do
        next unless test("[ -d #{current_path.join('files')} ]")
        puts capture(:tree, current_path.join('files'))
      end
    end

    desc "Stash files apply (replace destination files)"
    task :'apply' do
      next unless data_permit_write
      on release_roles :app do
        execute :sudo, shared_path.join('drupal-stash-files-apply.sh')
      end
    end

    desc "Stash files apply (merge)"
    task :'apply-merge' do
      next unless data_permit_write
      on release_roles :app do
        execute :sudo, shared_path.join('drupal-stash-files-apply-merge.sh')
      end
    end

    desc "Download stashed files"
    task :download => 'data' do
      on release_roles :app do
        FileUtils.rm_r 'data/files' unless !Dir.exists?('data/files')
        download! current_path.join('files'), 'data', recursive: true
      end
    end

    desc "Upload stashed files"
    task :upload => 'data' do
      invoke 'drupal:stash-files:remove'
      on release_roles :app do
        upload! File.join('data', 'files'), current_path.join('files'), recursive: true
      end
    end
  end

  desc "Stash files"
  task :'stash-files' do
    invoke 'drupal:stash-files:remove'
    on release_roles :app do
      execute :cp, '-RL --preserve=all', current_path.join(fetch(:files_path)), current_path.join('files')
    end
  end

  namespace :'stash-database' do
    desc "Remove stashed database"
    task :remove do
      on release_roles :app do
        within current_path.join(fetch(:app_path)) do
          execute :rm, current_path.join('database.sql')
        end
      end
    end

    desc "Download stashed database"
    task :download => 'data' do
      # Check if extist and possible run stash-database if not?
      on release_roles :app do
        download! current_path.join('database.sql'), 'data'
      end
    end

    desc "Upload stashed database"
    # TODO: 'data/database.sql'? Nah, makes no sense to download -> upload
    task :upload => 'data' do
      on release_roles :app do
        upload! File.join('data', 'database.sql'), current_path.join('database.sql')
      end
    end

    task :'apply' do
      next unless data_permit_write
      on release_roles :app do
        within current_path.join(fetch(:app_path)) do
          #TODO: drop before import?
          execute :drush, "sql-cli < \"#{current_path.join('database.sql')}\""
          invoke 'drupal:clear-cache'
        end
      end
    end
  end

  desc "Stash database"
  task :'stash-database' do
    on release_roles :app do
      within current_path.join(fetch(:app_path)) do
        #TODO: inconsistent use of quotes for paths, fix
        execute :drush, "sql-dump --result-file=\"#{current_path.join('database.sql')}\""
      end
    end
  end

  desc "Clear all caches"
    task :'clear-cache' do
    on release_roles :app do
      within release_path.join(fetch(:app_path)) do
        execute :drush, 'cache-clear all -y'
      end
    end
  end

  desc "Put site in maintenance mode"
  task :'site-offline' do
    on release_roles :app do
      within release_path.join(fetch(:app_path)) do
        execute :drush, 'vset maintenance_mode 1 -y'
        # invoke "drupal:clear_cache"
      end
    end
  end

  desc "Take site off maintenance mode"
  task :'site-online' do
    on release_roles :app do
      within release_path.join(fetch(:app_path)) do
        execute :drush, 'vset maintenance_mode 0 -y'
        # invoke "drupal:clear_cache"
      end
    end
  end

  desc 'Apply any database updates required (as with running update.php).'
  task :updatedb do
    on release_roles :app do
      within release_path.join(fetch(:app_path)) do
        execute :drush, 'updatedb -y'
      end
    end
  end

  #TODO restore/revert/import?
  #task :restore_database
end

namespace :deploy do
  before :starting, :set_command_map_paths do
    #SSHKit.config.command_map[:drupal_stash_files_apply] = shared_path.join('drupal-stash-files-apply.sh');
    #SSHKit.config.command_map[:drupal_stash_files_apply_merge] = shared_path.join('drupal-stash-files-apply-merge.sh');
  end
  before :check, :'drupal-install-scripts' do
    on release_roles :app do
      script = 'drupal-stash-files-apply.sh'
      template script, shared_path.join(script), 0750
      digest = template_digest(script, ->(data){ Digest::SHA256.hexdigest(data) })
      entry = sudoers_entry('drupal-deploy', "sha256:#{digest}", "#{shared_path.join(script)}")
      upload! entry, shared_path.join('suduers-files-apply')

      script = 'drupal-stash-files-apply-merge.sh'
      template script, shared_path.join(script), 0750
      digest = template_digest(script, ->(data){ Digest::SHA256.hexdigest(data) })
      entry = sudoers_entry('drupal-deploy', "sha256:#{digest}", "#{shared_path.join(script)}")
      #entry = sudoers_entry('drupal-deploy', "sha256:#{digest}", sha256_script_exec(shared_path.join(script), digest))
      upload! entry, shared_path.join('suduers-files-apply-merge')
    end
  end
  after :starting, 'composer:install_executable'
  after :starting, 'drush:install'
  after :starting, :backup_previous_revision_database do
    if fetch(:previous_revision)
      #invoke 'drupal:stash-database'
    end
  end
  after :publishing, 'drupal:site-offline'
# after :publishing, 'drupal:clear-cache'
  after :publishing, 'drupal:updatedb'
  after :publishing, 'drupal:site-online'
end
