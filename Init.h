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

//函数功能：打印登录界面
void loginMenu();

//函数功能：打印主菜单界面
void mainMenu();

//函数功能：覆盖主菜单界面
void coverMainMenu(int x);

/*函数功能：用方向键选择菜单或者输入数字选择菜单
 * line：当前光标所在行数
 * deta：第一个选项所在行（行数从0开始计算）
 * upper, lower：选项的上下界所在行（上界为最后一个选项的行数，下界为第一个选项的行数）
 * (*P)(int)：函数指针，选择哪个覆盖菜单
 * 返回值：选择的选项（1~9）（引用时判断是否为已有选项，如果不是则重新选择）
 */
int menuController(int line, int deta, int lower, int upper, void (*p)(int));


//函数功能：关于界面
void About();

#endif //V_SGMS_INIT_H
