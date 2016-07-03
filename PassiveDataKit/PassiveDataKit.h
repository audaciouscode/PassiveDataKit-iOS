//
//  PassiveDataKit.h
//  PassiveDataKit
//
//  Created by Chris Karr on 5/4/16.
//  Copyright © 2016 Audacious Software. All rights reserved.
//

@import UIKit;

//! Project version number for PassiveDataKit.
FOUNDATION_EXPORT double PassiveDataKitVersionNumber;

//! Project version string for PassiveDataKit.
FOUNDATION_EXPORT const unsigned char PassiveDataKitVersionString[];

extern NSString *const PDKCapabilityRationale;
extern NSString *const PDKLocationSignificantChangesOnly;
extern NSString *const PDKLocationAlwaysOn;
extern NSString *const PDKLocationRequestedAccuracy;
extern NSString *const PDKLocationRequestedDistance;
extern NSString *const PDKLocationInstance;
extern NSString *const PDKMixpanelToken;

extern NSString *const PDKGooglePlacesSpecificLocation;
extern NSString *const PDKGooglePlacesAPIKey;
extern NSString *const PDKGooglePlacesType;
extern NSString *const PDKGooglePlacesRadius;
extern NSString *const PDKGooglePlacesInstance;
extern NSString *const PDKGooglePlacesIncludeFullDetails;

typedef NS_ENUM(NSInteger, PDKDataGenerator) {
    PDKLocation,
    PDKGooglePlaces
};

@protocol PDKDataListener

- (void) receivedData:(NSDictionary *) data forGenerator:(PDKDataGenerator) dataGenerator;

@end

@protocol PDKGenerator

- (void) removeListener:(id<PDKDataListener>)listener;
- (void) addListener:(id<PDKDataListener>)listener options:(NSDictionary *) options;
+ (UIView *) visualizationForSize:(CGSize) size;

@end

@interface PassiveDataKit : NSObject

+ (PassiveDataKit *) sharedInstance;

- (BOOL) registerListener:(id<PDKDataListener>) listener forGenerator:(PDKDataGenerator) dataGenerator options:(NSDictionary *) options;
- (BOOL) unregisterListener:(id<PDKDataListener>) listener forGenerator:(PDKDataGenerator) dataGenerator;
- (NSArray *) activeListeners;

- (BOOL) logDataPoint:(NSString *) generator generatorId:(NSString *) generatorId source:(NSString *) source properties:(NSDictionary *) properties;
- (void) uploadDataPoints:(NSURL *) url window:(NSTimeInterval) uploadWindow complete:(void (^)(BOOL success, int uploaded)) completed;
- (BOOL) logEvent:(NSString *) eventName properties:(NSDictionary *) properties;
- (void) setMandatoryEventLogging:(BOOL) isMandatory;

- (NSString *) identifierForUser;
- (BOOL) setIdentifierForUser:(NSString *) newIdentifier;
- (void) resetIdentifierForUser;

- (NSString *) generator;
- (BOOL) setGenerator:(NSString *) newGenerator;
- (void) resetGenerator;

- (NSString *) generatorId;
- (BOOL) setGeneratorId:(NSString *) newIdentifier;
- (void) resetGeneratorId;

- (BOOL) mixpanelEnabled;
- (void) enableMixpanel:(NSString *) token;
- (void) disableMixpanel;

- (UIViewController *) dataReportController;

@end
