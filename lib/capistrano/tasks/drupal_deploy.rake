# Load default values the capistrano 3.x way.
# See https://github.com/capistrano/capistrano/pull/605
namespace :load do
  task :defaults do
    set :app_path, 'web' #??
  end
end

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
  desc "Backup database"
  task :backup_database do
    #release_roles(:all) ?
    if fetch(:previous_revision)
      on release_roles :app do
        within current_path.join(fetch(:app_path)) do
          #TODO: exclude cache tables etc, just testing for now
          #TODO: Promt instead of overwriting?
          execute :drush, "sql-dump > #{current_path}/DATABASE.sql"
        end
      end
    end
  end

  desc "Clear all caches"
    task :clear_cache do
    on release_roles :app do
      within release_path.join(fetch(:app_path)) do
        execute :drush, 'cache-clear all -y'
      end
    end
  end

  desc "Put site in maintenance mode"
  task :site_offline do
    on release_roles :app do
      within release_path.join(fetch(:app_path)) do
        execute :drush, 'vset maintenance_mode 1 -y'
        # invoke "drupal:clear_cache"
      end
    end
  end

  desc "Take site off maintenance mode"
  task :site_online do
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

  desc 'Clear all caches.'
  task :clearcache do
    on release_roles :app do
      within release_path.join(fetch(:app_path)) do
        execute :drush, 'cache-clear all'
      end
    end
  end

  #TODO restore/revert/import?
  #task :restore_database
end

namespace :deploy do
  after :starting, 'composer:install_executable'
  after :starting, 'drush:install'
  after :starting, 'drupal:backup_database'
  after :publishing, 'drupal:site_offline'
# after :publishing, 'drupal:clearcache'
  after :publishing, 'drupal:updatedb'
  after :publishing, 'drupal:site_online'
end
