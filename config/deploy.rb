## CAPISTRANO ##

# config valid only for Capistrano 3.1
lock '3.2.1'

set :application, 'ubnext'
set :repo_url, 'https://github.com/ub-digit/ubnext.git'

# Default branch is :master
# ask :branch, proc { `git rev-parse --abbrev-ref HEAD`.chomp }.call
set :branch, 'master'

# Default deploy_to directory is /var/www/my_app
# set :deploy_to, '/var/www/drupal/staging'

set :scm, :git
set :format, :pretty
set :log_level, :debug

# Default false
set :pty, false

set :linked_files, %w{web/sites/default/secret.settings.php}

# Default value for linked_dirs is []
set :linked_dirs, %w{web/sites/default/files}

# Default value for default_env is {}
# set :default_env, { path: "/opt/ruby/bin:$PATH" }

# Default value for keep_releases is 5
set :keep_releases, 5

## DRUPAL DEPLOY ##
set :app_path, 'web'
set :theme_path, 'sites/default/themes/ubnext'

## Composer ##
set :composer_roles, :app

## NPM ##
set :npm_roles, :app
set :npm_target_path, -> { release_path.join(fetch(:app_path), fetch(:theme_path)) }
set :npm_flags, '--silent --no-spin'
set :npm_prune_flags, ''

namespace :deploy do
  before :starting, :set_command_map_paths do
    SSHKit.config.command_map[:composer] = "php #{shared_path.join("composer.phar")}"
    SSHKit.config.command_map[:drush] = "#{shared_path.join("vendor/drush/drush/drush")}"
  end
  after :updated, :grunt_less do
    SSHKit.config.command_map[:grunt] = "#{release_path.join(fetch(:app_path), fetch(:theme_path), 'node_modules/.bin/grunt')}"
    on roles :app do 
      within release_path.join(fetch(:app_path), fetch(:theme_path)) do 
        execute :grunt, 'less'
      end
    end
  end
end

# We have no composer root level dependencies so far
Rake::Task['deploy:updated'].prerequisites.delete('composer:install')
