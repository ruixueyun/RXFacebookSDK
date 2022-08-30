//
//  RXFacebookService.h
//  RXFacebookSDK
//
//  Created by 陈汉 on 2022/8/30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^FBShareCallBack)(BOOL success);

@interface RXFacebookService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 注册Facebook
 */
- (void)FBRegistWithApplication:(UIApplication *)application
                  launchOptions:(NSDictionary *)launchOptions;

/**
 * 跳转openURL
 */
- (BOOL)FBApplication:(UIApplication *)application
              openURL:(NSURL *)url
              options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

#pragma mark -- <登录>
/**
 * Facebook登录
 * @param permissions 权限  必须
 */
- (void)FBLoginWithPermissions:(NSArray *)permissions;

/**
 * Facebook退出登录
 */
- (void)FBLogout;

#pragma mark -- <分享>
/**
 * Facebook分享
 * @param shareInfo 获取分享信息返回的内容  必须
 */
- (void)FBShareWithShareInfo:(NSDictionary *)shareInfo
                    complete:(FBShareCallBack)complete;

@end

NS_ASSUME_NONNULL_END
