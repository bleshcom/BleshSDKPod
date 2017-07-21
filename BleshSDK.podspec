Pod::Spec.new do |s|
  s.name         = 'BleshSDK'
  s.version      = '3.4.0.1'
  s.summary      = 'iOS library for Blesh iBeacon devices'
  s.description  = 'iOS library for Blesh iBeacon devices. Please refer to our documentation for details.'
  s.homepage     = 'http://blesh.com'
  s.author       = { "Blesh, Inc" => "contact@blesh.com" }
  s.platform     = :ios
  s.source       = { :git => "https://github.com/bleshcom/BleshSDKPod.git", :tag => "3.4.0.1", :branch => "IDFA" }
  s.source_files =  'BleshSDK.framework/Headers/*.h'
  s.vendored_frameworks = 'BleshSDK.framework'
  s.frameworks = 'AdSupport', 'AudioToolBox', 'SystemConfiguration', 'Accelerate', 'CoreLocation', 'CoreBluetooth', 'CoreTelephony', 'UserNotifications'
  s.requires_arc = true
  #s.xcconfig  =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/BleshSDK"',
                  #'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/Headers/BleshSDK"' }
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2013 Blesh, Inc. All rights reserved.
      LICENSE
  }

  s.documentation_url = 'https://github.com/bleshinc/docs-v3/wiki/iOS-integration'
end