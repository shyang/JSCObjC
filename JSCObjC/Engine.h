//
//  Engine.h
//  JSCObjC
//
//  Created by shaohua on 6/17/16.
//  Copyright © 2016 syang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@interface Engine : NSObject

@property (nonatomic) JSVirtualMachine *virtualMachine;
@property (nonatomic) JSContext *context;

@end
