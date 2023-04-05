// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_FUNCTIONLIB_H
#define V_SGMS_FUNCTIONLIB_H

#include <windows.h>

/*函数功能：获取光标位置
 *函数参数：无
 *函数返回值：光标位置
 */
COORD getCursor();

/*函数功能：控制台光标移动到指定位置
 *函数参数：x,y
 *函数返回值：无
 */
void setCursor(int x, int y);

/*函数功能：设置窗口标题
 *函数参数：lpTitle
 *函数返回值：无
 */
VOID setTitle(LPCSTR lpTitle);

/*函数功能：设置窗口大小
 *函数参数：width,height
 *函数返回值：无
 */
void setWindowSize(int x, int y);

/*函数功能：打开网页
 *函数参数：website
 *函数返回值：无
 */
void openWeb(char *website);

#endif //V_SGMS_FUNCTIONLIB_H
