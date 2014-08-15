//
// BCOVIMAAdsRequestPolicy.h
// BCOVIMA
//
// Copyright (c) 2014 Brightcove, Inc. All rights reserved.
// License: https://accounts.brightcove.com/en/terms-and-conditions
//

#import <Foundation/Foundation.h>


@protocol BCOVPlaybackSession;

@class RACSignal;


/**
 * Policy object to generate IMAAdsRequests for use by a
 * given input playback session.
 */
@interface BCOVIMAAdsRequestPolicy : NSObject

/**
 * Returns an ads request policy that checks the BCOVVideo object in each
 * playback session for the VMAP ad tag URL to request. If the video object's
 * properties contains an entry whose key is `kBCOVIMAAdTag`, the value
 * of that entry is assumed to be a NSString containing the VMAP ad tag URL.
 * That URL will be used to construct a VMAP IMAAdsRequest for that playback 
 * session.
 *
 * @return An ads request policy that generates VMAP IMAAdsRequests from
 * information in each playback session's `BCOVVideo.properties`.
 */
+ (instancetype)videoPropertiesVMAPAdTagUrlAdsRequestPolicy;

/**
 * Returns an ads request policy that checks the BCOVVideo object in each
 * playback session for the VMAP ad tag URL to request. If the video object's
 * properties contains an entry whose key is `kBCOVIMAAdTag`, the value
 * of that entry is assumed to be a NSString containing the VMAP ad tag URL.
 * That URL will be used to construct a VMAP IMAAdsRequest for that playback 
 * session.
 *
 * @param companionAdSlots An array of IMACompanionAdSlot objects to include
 * in the IMAAdsRequest.
 * @return An ads request policy that generates VMAP IMAAdsRequests from
 * information in each playback session's `BCOVVideo.properties`.
 */
+ (instancetype)videoPropertiesVMAPAdTagUrlAdsRequestPolicyWithCompanionAdSlots:(NSArray *)companionAdSlots;

/**
 * Returns an ads request policy that generates a VMAP IMAAdsRequest with the
 * specified ad tag URL and companion slots for every playback session.
 *
 * @param VMAPAdTagUrl The ad tag URL to include in the IMAAdsRequest this
 * policy generates. Currently, only VMAP ad tag URLs are supported.
 * @param companionAdSlots An array of IMACompanionAdSlot objects to include
 * in the IMAAdsRequest.
 * @return An ads request policy that generates VMAP IMAAdsRequests from
 * the specified parameters.
 */
+ (instancetype)adsRequestPolicyWithVMAPAdTagUrl:(NSString *)VMAPAdTagUrl companionAdSlots:(NSArray *)companionAdSlots;

@end


@interface BCOVIMAAdsRequestPolicy (Deprecated)

- (RACSignal *)signalWithValue:(id<BCOVPlaybackSession>)inputSession __attribute((deprecated("Use one of the provided ad policies above instead.")));

@end
