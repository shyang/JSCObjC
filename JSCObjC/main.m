//
//  main.m
//  JSCObjC
//
//  Created by shaohua on 6/17/16.
//  Copyright © 2016 syang. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "Engine.h"

int main(int argc, char * argv[]) {
    @autoreleasepool {
        NSURL *jsURL = [[NSBundle mainBundle] URLForResource:@"index" withExtension:@"js"];

        Engine *e = [[Engine alloc] init];
        [e.context evaluateScript:[NSString stringWithContentsOfURL:jsURL encoding:NSUTF8StringEncoding error:NULL]];

        return UIApplicationMain(argc, argv, nil, @"AppDelegate");
    }
}
