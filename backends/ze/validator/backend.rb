# frozen_string_literal: true
require 'ze/validator/framework'
source = File.expand_path('../../../utils/validator/backend.rb', __dir__)
if File.file?(source)
  require source
else
  require 'thapi/validator/backend'
end

# Level Zero is the only built-in backend. Bindings and model code are loaded
# only when it is selected; future backend plugins own their own dependencies.
THAPIValidator::Backends.register('level_zero', aliases: ['ze']) do |**options|
  require 'ze/validator/state_object'
  ZEValidator::StateObject.new(**options)
end
