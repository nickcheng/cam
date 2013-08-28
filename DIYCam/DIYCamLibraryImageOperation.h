//
//  DIYCamLibraryImageOperation.h
//  cam
//
//  Created by Andrew Sliwinski on 7/5/12.
//  Copyright (c) 2012 DIY, Co. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AssetsLibrary/AssetsLibrary.h>

typedef void (^saveToLibraryCompletionBlock)();

@interface DIYCamLibraryImageOperation : NSOperation
{
    id dataset;
}

@property BOOL              complete;
@property NSUInteger        size;
@property NSURL             *path;
@property NSError           *error;
@property ALAssetsLibrary   *library;
@property (nonatomic, copy) saveToLibraryCompletionBlock saveToLibraryCompletionHandler;

- (id)initWithData:(id)data;

@end
