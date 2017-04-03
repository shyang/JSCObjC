### Create objc class/method on-the-fly in javascript


`index.js`:

```javascript
var c = newclass('AppDelegate', 'NSObject', ['UIApplicationDelegate'])

newmethod(c, 'application:didFinishLaunchingWithOptions:', function(application, options) {
  print('inside');
  return true;
})
```

Body of the method will be invoked:
```sh
2016-06-18 16:44:41.307 JSCObjC[4711:517242] inside
```

#### Next

```objc
static void forwardInvocationSuper(...) {

    // convert arguments from -[NSInvocation getArgument:atIndex:] to an NSArray

    id ret = [function callWithArguments:args];

    // convert the return value to -[NSInvocation setReturnValue:]
}
```
