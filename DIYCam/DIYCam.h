//
//  DIYCam.h
//  cam
//
//  Created by Andrew Sliwinski on 7/5/12.
//  Copyright (c) 2012 DIY, Co. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import "DIYAV.h"
#import "DIYCamUtilities.h"
#import "DIYCamFileOperation.h"
#import "DIYCamLibraryImageOperation.h"
#import "DIYCamLibraryVideoOperation.h"

@protocol DIYCamDelegate;
@interface DIYCam : UIView <DIYAVDelegate>

@property (nonatomic, weak) id<DIYCamDelegate> delegate;

- (void)setupWithOptions:(NSDictionary *)options;

#pragma mark - Status
- (BOOL)getRecordingStatus;
- (DIYAVMode)getCamMode;
- (void)setCamMode:(DIYAVMode)mode;
- (DIYAVFlashMode)getFlash;
- (void)setFlash:(DIYAVFlashMode)flash;
- (void)flipCamera;

#pragma mark - Capture
- (void)stopSession;
- (void)startSession;

- (void)capturePhoto;
- (void)captureVideoStart;
- (void)captureVideoStop;

@end

//

@protocol DIYCamDelegate <NSObject>
@required
- (void)camDidFail:(DIYCam *)cam withError:(NSError *)error;

- (void)camModeWillChange:(DIYCam *)cam mode:(DIYAVMode)mode;
- (void)camModeDidChange:(DIYCam *)cam mode:(DIYAVMode)mode;

- (void)camCaptureStarted:(DIYCam *)cam;
- (void)camCaptureStopped:(DIYCam *)cam;
- (void)camCaptureProcessing:(DIYCam *)cam;
- (void)camCaptureComplete:(DIYCam *)cam withAsset:(NSDictionary *)asset;
- (void)camCaptureLibraryOperationComplete:(DIYCam *)cam withAsset:(NSDictionary *)asset;

@end

//