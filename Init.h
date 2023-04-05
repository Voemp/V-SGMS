// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_INIT_H
#define V_SGMS_INIT_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "FunctionLib.h"

#define IN_BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x90)
#define IN_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xb0)
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)
#define IN_REDWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfc)
#define IN_CYANWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfb)

#define TEMPKEY -32
#define UPKEY 72
#define DOWNKEY 80

//函数功能：打印欢迎界面
void welcomeInit();

//登录界面声明
extern char *loginMenu[7];

//主菜单声明
extern char *mainMenu[10];

//学生成绩查询菜单（教师版）声明
extern char *studentGradeQueryMenu1[12];

//学生成绩管理界面声明
extern char *studentGradeManageMenu1[8];

//退出程序确认界面声明
extern char *exitConfirmMenu[6];

//函数功能：关于界面
void About();


/*函数功能：绘制菜单
 * **menu：选择哪个覆盖菜单
 * RowSize：菜单的行数
 * line：光标所在行
 * confirm：是否确认
 */
void drawMenu(char *menu[], int RowSize, int line, int confirm);

/*函数功能：用方向键选择菜单或者输入数字选择菜单
 * upper, lower：选项的上下界所在行（上界为最后一个选项的行数，下界为第一个选项的行数）
 * **menu：选择哪个覆盖菜单
 * 返回值：选择的选项（1~9）（引用时判断是否为已有选项，如果不是则重新选择）
 */
int menuController(char *menu[], int lower, int upper);

#endif //V_SGMS_INIT_H
