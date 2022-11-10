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
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 */
- (void)FBLoginWithPermissions:(NSArray *)permissions
                  migrate_args:(id _Nullable)migrate_args
                   sign_fields:(NSArray * _Nullable)sign_fields;

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
