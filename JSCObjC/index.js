var c = newclass('AppDelegate', 'NSObject', ['UIApplicationDelegate'])

newmethod(c, 'application:didFinishLaunchingWithOptions:', function(application, options) {
  print('inside');
  return true;
})
