//
//  Engine.m
//  JSCObjC
//
//  Created by shaohua on 6/17/16.
//  Copyright © 2016 syang. All rights reserved.
//

#import <objc/runtime.h>
#import <objc/message.h>
#import <UIKit/UIKit.h>

#import "Engine.h"
#import "PrivateApi.h"

static void forwardInvocationSuper(id self, SEL _cmd, NSInvocation *invoke, Class cls) {
    id target = invoke.target;
    SEL selector = invoke.selector;

    if (!cls) {
        cls = object_getClass(target);
    }
    JSValue *function = objc_getAssociatedObject(cls, selector);
    [function callWithArguments:nil];
}

static void forwardInvocation(id self, SEL _cmd, NSInvocation *invoke) {
    forwardInvocationSuper(self, _cmd, invoke, Nil);
}

@interface Engine () <UIApplicationDelegate>

@end

@implementation Engine

- (instancetype)init {
    if (self = [super init]) {
        _virtualMachine = [[JSVirtualMachine alloc] init];
        _context = [[JSContext alloc] initWithVirtualMachine:_virtualMachine];
        [self injectFunctions];
    }
    return self;
}

- (void)injectFunctions {
    [_context setExceptionHandler:^(JSContext *context, JSValue *value) {
        NSLog(@"%@", value);
    }];

    _context[@"print"] = ^(NSString *msg) {
        NSLog(@"%@", msg);
    };

    _context[@"newclass"] = ^(NSString *clsName, NSString *superName, NSArray<NSString *> *protocols) {
        const char *name = clsName.UTF8String;
        Class cls = objc_getClass(name);
        if (!cls) {
            Class superclass = NSClassFromString(superName);
            cls = objc_allocateClassPair(superclass, name, 0);
            objc_registerClassPair(cls);

            for (NSString *p in protocols) {
                Protocol *protocol = objc_getProtocol(p.UTF8String);
                class_addProtocol(cls, protocol);
            }
            class_addMethod(cls, @selector(forwardInvocation:), (IMP)forwardInvocation, "v@:@");
        }
        return (id)cls;
    };

    _context[@"newmethod"] = ^(id cls, NSString *selector, JSValue *func) {
        SEL sel = NSSelectorFromString(selector);

        NSMethodSignature *sig = [cls instanceMethodSignatureForSelector:sel];
        NSCAssert(sel, @"no sig");
        const char *types = [sig _typeString].UTF8String;

        objc_setAssociatedObject(cls, sel, func, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

        IMP fp = _objc_msgForward;
#if !TARGET_CPU_ARM64
        if ([sig methodReturnLength] > 8) {
            fp = _objc_msgForward_stret;
        }
#endif
        BOOL added = class_addMethod(cls, sel, fp, types /* types can not be NULL? */);
        NSCAssert(added, @"not added");
    };
}

@end
