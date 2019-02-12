/**
 * @header BleshConfig.h
 * @brief  BleshConfig
 * @author Anıl TAŞKIRAN
 *
 * @link https://www.blesh.com
 * @copyright © 2019 Blesh. All rights reserved.
 * Created by Anıl T. on 24.01.2019.
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BleshConfig : NSObject

@property (nonatomic, assign) BOOL adsEnabled;

// This method using for disabling or enabling to ads. Default value is true.
-(id) initWithAdsEnabled:(BOOL) adsEnabled;

// If you want to check isAdsEnabled property please use this function.
+ (BOOL) isAdsEnabled;


NS_ASSUME_NONNULL_END
@end

