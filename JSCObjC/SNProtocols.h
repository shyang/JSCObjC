//
//  SNProtocols.h
//  ScriptingNative
//
//  Created by shaohua on 5/20/16.
//  Copyright © 2016 syang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>

@interface SNProtocols : NSObject <
    UIPopoverBackgroundViewMethods,

    // Foundation.framework
    NSCacheDelegate,
    NSFileManagerDelegate,
    NSKeyedArchiverDelegate,
    NSKeyedUnarchiverDelegate,
    NSMetadataQueryDelegate,
    NSNetServiceDelegate,
    NSNetServiceBrowserDelegate,
    NSPortDelegate,
    NSMachPortDelegate,
    NSStreamDelegate,
    NSURLConnectionDelegate,
    NSURLConnectionDataDelegate,
    NSURLConnectionDownloadDelegate,
    NSURLSessionDelegate,
    NSURLSessionTaskDelegate,
    NSURLSessionDataDelegate,
    NSURLSessionDownloadDelegate,
    NSUserActivityDelegate,
    NSXMLParserDelegate,

    // MessageUI.framework
    MFMailComposeViewControllerDelegate,
    MFMessageComposeViewControllerDelegate,

    // UIKit.framework
    NSLayoutManagerDelegate,
    NSTextStorageDelegate,
    UIAccelerometerDelegate,
    UIActionSheetDelegate,
    UIAdaptivePresentationControllerDelegate,
    UIAlertViewDelegate,
    UIApplicationDelegate,
    UIBarPositioningDelegate,
    UICollectionViewDataSource,
    UICollectionViewDelegate,
    UICollectionViewDelegateFlowLayout,
    UICollisionBehaviorDelegate,
    UIDocumentInteractionControllerDelegate,
    UIDocumentMenuDelegate,
    UIDocumentPickerDelegate,
    UIDynamicAnimatorDelegate,
    UIGestureRecognizerDelegate,
    UIImagePickerControllerDelegate,
    UINavigationBarDelegate,
    UINavigationControllerDelegate,
    UIPageViewControllerDataSource,
    UIPageViewControllerDelegate,
    UIPickerViewAccessibilityDelegate,
    UIPickerViewDataSource,
    UIPickerViewDelegate,
    UIPopoverControllerDelegate,
    UIPopoverPresentationControllerDelegate,
    UIPrintInteractionControllerDelegate,
    UIPrinterPickerControllerDelegate,
    UIScrollViewAccessibilityDelegate,
    UIScrollViewDelegate,
    UISearchBarDelegate,
    UISearchControllerDelegate,
    UISearchDisplayDelegate,
    UITabBarControllerDelegate,
    UITabBarDelegate,
    UITableViewDataSource,
    UITableViewDelegate,
    UITextFieldDelegate,
    UITextInputDelegate,
    UITextViewDelegate,
    UIToolbarDelegate,
    UIVideoEditorControllerDelegate,
    UIViewControllerTransitioningDelegate,
    UIWebViewDelegate
>

@end
