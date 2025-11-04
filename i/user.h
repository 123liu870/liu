#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 套餐信息结构体
typedef struct {
    char packageId[20];    // 套餐编号（唯一）
    float monthlyFee;      // 月资费
    int callDuration;      // 通话时长（分钟）
    int flow4G;            // 4G流量（MB）
    int broadband;         // 宽带带宽（M，0表示无）
    int intentCount;       // 意向客户数
} Package;

// 用户信息结构体
typedef struct {
    char userId[20];       // 用户编号（唯一）
    char userName[50];     // 用户名
    char currentPackageId[20]; // 当前套餐编号
    int callDemand;        // 通话需求（分钟）
    int flowDemand;        // 流量需求（MB）
    int broadbandDemand;   // 宽带需求（0=不需要）
    float consumption;     // 近3个月月均消费
} User;

// 全局变量声明
extern Package* packageList;   // 动态套餐列表
extern int totalPackages;      // 套餐总数
extern User* userList;         // 动态用户列表
extern int totalUsers;         // 用户总数
extern User currentUser;       // 当前登录用户
extern Package matchedPackages[10]; // 匹配的套餐
extern int matchedCount;       // 匹配数量

// 文本文件路径（可修改为绝对路径）
#define PACKAGE_FILE "packages.txt"
#define USER_FILE "users.txt"

// 工具函数
void clearInputBuffer();                  // 清空输入缓冲区
int isStrEmpty(const char* str);          // 判断字符串是否为空
void trimStr(char* str);                  // 去除字符串首尾空格

// 文件操作函数
int loadPackagesFromText();               // 从文本文件加载套餐
int savePackagesToText();                 // 保存套餐到文本文件
int loadUsersFromText();                  // 从文本文件加载用户
int saveUsersToText();                    // 保存用户到文本文件
User* findUser(const char* userId);       // 查找用户

// 核心功能函数
void inputDemandByForm();                 // 填写需求调查
void calcUserStar();                      // 计算用户星级
void matchPackagesByDemand();             // 匹配套餐
void showMatchedPackages();               // 显示推荐套餐
void queryUserPackage();                  // 查询个人套餐
void applyPackageChange();                // 变更套餐
void userFunctionMenu();                  // 用户功能菜单

#endif