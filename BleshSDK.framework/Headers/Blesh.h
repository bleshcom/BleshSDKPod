/**
 * @header Blesh.h
 * @brief  BleshSDK
 * @author Anıl TAŞKIRAN
 *
 * @version    4.0.0
 * @link https://www.blesh.com
 * @copyright © 2018 Blesh. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN
__IOS_AVAILABLE(8.0)
@interface Blesh : NSObject <UIApplicationDelegate, CBPeripheralManagerDelegate>


/// Use this instance for calling Blesh methods.
+ (Blesh *) sharedInstance;

/** If you have to share any Integration Id with Blesh, add this method before init.
 *
 *  @param integrationId   unique customerId which will be transferred via BleshAPI
 */
- (Blesh *) integrationId: (NSString *) integrationId;

/** If you have to share any optional parameter with Blesh, add this method before init.
 *
 *  @param optionalKey     optional parameters
 */
- (Blesh *) optionalKey: (NSString *) optionalKey;

/**
 * @brief This methods initialize Blesh SDK.
 * @discussion Objective-C
 * @code
 *
 * // with Integration Id and Optional Key
 * [[[[Blesh sharedInstance] integrationId: @"BleshIntegrationId"] optionalKey: @"BleshOptinalKey"] initBlesh];
 *
 * // with one of them
 * [[[Blesh sharedInstance] integrationId: @"BleshIntegrationId"] initBlesh];
 *
 * // none of them
 * [[Blesh sharedInstance] initBlesh];
 * @endcode
 *
 * Swift
 * @code
 *
 * // with Integration Id and Optional Key
 * Blesh.sharedInstance().integrationId("BleshIntegrationId").optionalKey("BleshOptinalKey").initBlesh()
 *
 * // with one of them
 * Blesh.sharedInstance().integrationId("BleshIntegrationId").initBlesh()
 *
 * // none of them
 * Blesh.sharedInstance().initBlesh()
 * @endcode
 *
 */
- (void) initBlesh;

// BleshSDK needs to be notified about incoming notification interactions.

/**
 * @brief Available (iOS 10.0, *) BleshSDK needs to be notified about incoming notification interactions.
 *
 * For our clients who use UNUserNotificationCenterDelegate, the following method must be implemented on:
 *
 * func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void)
 *
 * func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void)
 */
- (void) bleshReceivedUNNotification            :(UNNotification *) notification NS_AVAILABLE_IOS(10_0);


/**
 * @brief For backward compatibility for devices prior to iOS 10.
 *
 * For our clients who use UILocalNotification, the following method must be implemented on:
 *
 * @code
 func application(_ application: UIApplication, handleActionWithIdentifier identifier: String?, for notification: UILocalNotification, completionHandler: @escaping () -> Void) {
 Blesh.sharedInstance().bleshReceivedLocalNotification(notification)
 }
 * @endcode
 *
 * @code
 func application(_ application: UIApplication, didReceive notification: UILocalNotification) {
 Blesh.sharedInstance().bleshReceivedLocalNotification(notification)
 }
 * @endcode
 *
 * @code
 *
 func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
 if let notification = launchOptions![UIApplicationLaunchOptionsKey.localNotification] as? UILocalNotification {
 Blesh.sharedInstance().bleshReceivedLocalNotification(notification)
 }
 return true
 }
 * @endcode
 */
- (void) bleshReceivedLocalNotification         :(UILocalNotification *) notification NS_DEPRECATED_IOS(4_0, 10_0, "Use bleshReceivedUNNotification for version 10.0, *");


/**
 * @brief For backward compatibility for devices prior to iOS 10.
 *
 * For our clients who use application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo, the following method must be implemented on:
 *
 * @code
 func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any]) {
 Blesh.sharedInstance().bleshReceivedRemoteNotification(userInfo)
 }
 * @endcode
 *
 */
- (void) bleshReceivedRemoteNotification        :(NSDictionary *) userInfo NS_DEPRECATED_IOS(3_0, 10_0, "Use bleshReceivedUNNotification for version 10.0, *");

/**
 * @brief BleshSDK needs to be notified about incoming remote notification with content.
 *
 * The following method must be implemented on:
 *
 * application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;
 *
 * @code
 func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any], fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
 Blesh.sharedInstance().bleshReceivedRemoteNotification(userInfo) { (result) in
 completionHandler(result)
 }
 }
 * @endcode
 */
- (void) bleshReceivedRemoteNotification        :(NSDictionary *) userInfo
                          fetchCompletionHandler: (void (^)(UIBackgroundFetchResult))completionHandler;


/**
 * @brief BleshSDK needs to know deviceToken for sending remote push.
 *
 * The following method must be implemented on:
 *
 * - (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
 *
 * @code
 func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
 Blesh.sharedInstance().bleshReceivedDeviceToken(deviceToken)
 }
 * @endcode
 */
- (void) bleshReceivedDeviceToken :(NSData *) deviceToken;

/** Blesh SDK gives the information that customer clicked on the notification.
 *
 * Once the user receives the push notification and opens it;
 * BleshSDK informs your app that the user has interacted with your content.
 * In order to receive this information, implement the code block below to your app.
 *
 *
 * @code
 * // Objective-C
 * [[Blesh sharedInstance] didUserInteractWithCampaignView:^(NSString * actionType, NSString * actionValue, NSString * actionFeedbackValue) {
 *
 * }];
 *
 * // Swift
 * Blesh.sharedInstance().didUserInteractWithCampaignView = { actionType, actionValue, actionFeedbackValue in
 *
 * }
 */
@property (nonatomic, copy) void (^didUserInteractWithCampaignView)(NSString * actionType, NSString * actionValue, NSString * actionFeedbackValue);

- (void) bleshPerformFetchWithCompletionHandler :(void (^)(UIBackgroundFetchResult))completionHandler;

@end


NS_ASSUME_NONNULL_END

