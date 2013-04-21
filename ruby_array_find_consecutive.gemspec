Gem::Specification.new do |gem|
  gem.name          = 'ruby_array_find_consecutive'
  gem.version       = '0.0.1'
  gem.authors       = ['Richard Calahan']
  gem.email         = ['richard@calahan.me']
  gem.description   = 'Provides a C level extension to Ruby, Array#find_consecutive'
  gem.summary       = 'Array#find_consecutive implementation'
  gem.homepage      = ''
  gem.files         = `git ls-files`.split($/)
  gem.extensions    = ['ext/ruby_array_find_consecutive/extconf.rb']
  gem.executables   = gem.files.grep(%r{^bin/}).map{ |f| File.basename(f) }
  gem.test_files    = gem.files.grep(%r{^(test|spec|features)/})
  gem.require_paths = ['lib']
  gem.add_development_dependency 'rake'
  gem.add_development_dependency 'rake-compiler'
  gem.add_development_dependency 'rspec'
  gem.test_files  = Dir.glob "spec/**/*_spec.rb"
end
