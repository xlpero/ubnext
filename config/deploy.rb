# config valid only for Capistrano 3.1
lock '3.2.1'

set :application, 'ubnext'
set :repo_url, 'https://github.com/ub-digit/ubnext.git'

# Default branch is :master
# ask :branch, proc { `git rev-parse --abbrev-ref HEAD`.chomp }.call
set :branch, 'master'

# Default deploy_to directory is /var/www/my_app
set :deploy_to, '/srv/www/drupal7/ubnext'

set :scm, :git
set :format, :pretty
set :log_level, :debug

# Default false
set :pty, false

set :linked_files, %w{web/sites/default/secret.settings.php}

# Default value for linked_dirs is []
# set :linked_dirs, %w{bin log tmp/pids tmp/cache tmp/sockets vendor/bundle public/system}

# Default value for default_env is {}
# set :default_env, { path: "/opt/ruby/bin:$PATH" }

# Default value for keep_releases is 5
set :keep_releases, 5

namespace :deploy do
  SSHKit.config.command_map[:composer] = "php #{shared_path.join("composer.phar")}"
  SSHKit.config.command_map[:drush] = "#{shared_path.join("vendor/drush/drush/drush")}"
end

# We have no composer root level dependencies so far
Rake::Task['deploy:updated'].prerequisites.delete('composer:install')
