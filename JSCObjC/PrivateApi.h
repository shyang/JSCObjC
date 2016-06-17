//
//  PrivateApi.h
//  JSCObjC
//
//  Created by shaohua on 6/3/16.
//  Copyright © 2016 syang. All rights reserved.
//

#pragma once

id __NSMakeSpecialForwardingCaptureBlock(const char *signature, id block);

@interface NSInvocation ()

- (void)invokeUsingIMP:(IMP)fp;

@end

@interface NSMethodSignature ()

- (NSString *)_typeString;

@end
