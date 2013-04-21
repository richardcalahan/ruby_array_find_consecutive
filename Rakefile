require 'rake'
require 'rake/extensiontask'
require 'rspec/core/rake_task'

RSpec::Core::RakeTask.new :spec
Rake::ExtensionTask.new 'ruby_array_find_consecutive'

task :default => [ :compile, :spec ]
