#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


//套餐结构体
typedef struct Package {
    char pkgId[20];        // 套餐编号
    float monthlyFee;      // 月资费（元）
    int callDuration;      // 通话时长（分钟）
    float dataFlow;        // 4G流量（GB）
    float broadband;       // 宽带带宽（Mbps）
    int discountLevel;     // 套餐优惠力度等级（1-5级，5级最高）
    int isMatch;           // 匹配类型（0=不匹配，1=完全匹配，2=近似匹配）
} Package;

//用户结构体：包含用户基础信息、套餐使用数据及星级
typedef struct User {
    char userId[20];       // 用户ID（与前端登录ID同步）
    char userPwd[20];      // 用户密码（前端校验后同步）
    char userName[20];     // 用户名
    char selectedPkg[20];  // 已选套餐编号
    int useYears;          // 套餐使用年限（年）
    float totalCost;       // 累计消费金额（元）
    int userStar;          // 用户星级（1-5星）
} User;

//全局变量声明
extern char frontEndBuffer[1024];  // 接收前端数据缓冲区
extern char backEndBuffer[1024];   // 发送前端数据缓冲区
extern Package allPackages[50];    // 存储管理员维护的所有套餐
extern User currentUser;           // 当前登录用户信息
extern int pkgCount;               // 总套餐数量
extern int matchedPkgCount;        // 匹配到的套餐数量
extern Package matchedPackages[20];// 匹配结果列表

//函数声明
// 初始化与前后端交互模块
void initUserSystem();                  // 初始化系统（与前端建立连接，同步套餐数据）
void receiveDataFromFrontEnd();         // 接收前端数据
void sendDataToFrontEnd(const char* data); // 向前端发送数据

// 用户核心功能模块
void userLogin();                       // 用户登录
Package inputDemandByForm();            // 调查表填写
void calcUserStar();                    // 计算用户星级
void matchPackagesByDemand(Package demand); // 按需求匹配套餐
void showMatchedPackages();             // 展示推荐套餐并确认选择
void queryUserPackage();                // 查询本人套餐信息
void searchPackage();                   // 搜索窗口
void applyPackageChange();              // 变更套餐需求
void exitUserSystem();                  // 退出系统

#endif // USER_H