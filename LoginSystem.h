// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_LOGINSYSTEM_H
#define V_SGMS_LOGINSYSTEM_H

#include "struct.h"

/*函数功能：登录系统，可通过方向上下键换行，回车键确认
 * 函数参数：用户链表头指针,起始光标位置x,起始光标位置y
 * 函数返回值：登录成功返回1,登录失败返回0
 */
int loginMod(USER *temp_use);

/*函数功能：注册系统，可通过方向上下键换行，回车键确认
 * 函数参数：用户链表头指针,起始光标位置x,起始光标位置y
 * 函数返回值：注册成功返回1,注册失败返回0
 */
int registerMod(USER *temp_user);

#endif //V_SGMS_LOGINSYSTEM_H
