# frozen_string_literal: true
# Compatibility names for existing Level Zero extensions and YAML users.
source = File.expand_path('../../../utils/validator/framework.rb', __dir__)
if File.file?(source)
  require source
else
  require 'thapi/validator/framework'
end
module ZEValidator
  ConfigurationError = THAPIValidator::ConfigurationError
  Registry = THAPIValidator::Registry
  Rules = THAPIValidator::Rules
end
