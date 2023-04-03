// Created by VoidEmpty on 2023/3/29.
#include "Init.h"

//函数功能：打印欢迎界面
void welcomeInit() {
    system("cls");
    printf("****************************************************\n");
    printf(" VV        VV          SSSS    GGGG   M   M   SSSS  \n");
    printf(" VV       VV          S       G    G  MM MM  S      \n");
    printf(" VV      VV           S       G       MM MM  S      \n");
    printf(" VV     VV     =====   SSSS   G       M M M   SSSS  \n");
    printf(" VV    VV                  S  G   GG  M   M       S \n");
    printf(" VV   VV                   S  G    G  M   M       S \n");
    printf("  VVV                  SSSS    GGGG   M   M   SSSS  \n");
    printf("****************************************************\n");
    printf("          欢迎使用V-SIMS学生成绩管理系统！           \n");
    printf("****************************************************\n");
    printf("               作者：VoidEmpty\n");
    printf("****************************************************\n");
    IN_CYANWORD;
    printf("程序正在加载中[□□□□□□□□□□]0%\r");
    Sleep(300);
    printf("程序正在加载中[■■□□□□□□□□]20%\r");
    Sleep(300);
    printf("程序正在加载中[■■■■□□□□□□]40%\r");
    Sleep(300);
    printf("程序正在加载中[■■■■■■□□□□]60%\r");
    Sleep(300);
    printf("程序正在加载中[■■■■■■■■□□]80%\r");
    Sleep(300);
    printf("程序正在加载中[■■■■■■■■■■]100%\n");
    Sleep(300);
    printf("程序加载完成！\n");
    IN_WHITE;
    Sleep(400);
}

//函数功能：打印登录界面
void loginMenu() {
    system("cls");
    printf("********************************\n");
    printf("*           登录系统           *\n");
    printf("********************************\n");
    printf("*        1.登录已有帐号        *\n");
    printf("*        2.注册新的帐号        *\n");
    printf("*        3.退出程序            *\n");
    printf("********************************\n");
}

//函数功能：打印主菜单界面
void mainMenu() {
    system("cls");
    printf("********************************\n");
    printf("*           主菜单             *\n");
    printf("********************************\n");
    printf("*        1.学生成绩查询        *\n");
    printf("*        2.学生成绩管理        *\n");
    printf("*        3.修改密码            *\n");
    printf("*        4.退出登录            *\n");
    printf("*        5.退出程序            *\n");
    printf("*        6.关于                *\n");
    printf("********************************\n");
    IN_REDWORD;
    printf("请使用↑、↓和enter来实现选择和执行命令\n");
    printf("或者输入每个命令前面的数字来执行命令\n");
    IN_WHITE;
    printf("********************************\n");
}

//函数功能：覆盖主菜单界面
void coverMainMenu(int x) {
    switch (x) {
        case 1:
            printf("*        1.学生成绩查询        *\n");
            break;
        case 2:
            printf("*        2.学生成绩管理        *\n");
            break;
        case 3:
            printf("*        3.修改密码            *\n");
            break;
        case 4:
            printf("*        4.退出登录            *\n");
            break;
        case 5:
            printf("*        5.退出程序            *\n");
            break;
        case 6:
            printf("*        6.关于                *\n");
            break;
        default:
            break;
    }
}

//函数功能：退出程序确认界面
void exitConfirmMenu() {
    system("cls");
    printf("********************************\n");
    printf("*           退出程序           *\n");
    printf("********************************\n");
    printf("*        1.确认退出程序        *\n");
    printf("*        2.返回主菜单          *\n");
    printf("********************************\n");
    IN_REDWORD;
    printf("请使用↑、↓和enter来实现选择和执行命令\n");
    printf("或者输入每个命令前面的数字来执行命令\n");
    IN_WHITE;
    printf("********************************\n");
}

//函数功能：覆盖退出程序确认
void coverExitConfirmMenu(int x) {
    switch (x) {
        case 1:
            printf("*        1.确认退出程序        *\n");
            break;
        case 2:
            printf("*        2.返回主菜单          *\n");
            break;
        default:
            break;
    }
}

//函数功能：关于界面
void About() {
    system("cls");
    printf("********************************************\n");
    printf("*                   关于                   *\n");
    printf("********************************************\n");
    printf("*    Void-StudentGradeManagementSystem     *\n");
    printf("********************************************\n");
    printf("*             作者：VoidEmpty              *\n");
    printf("*             版本：1.0                    *\n");
    printf("*             日期：2023.04.01             *\n");
    printf("*             作者Github：                 *\n");
    IN_CYANWORD;
    printf("*         https://github.com/Voemp         *\n");
    IN_WHITE;
    printf("********************************************\n");
    IN_REDWORD;
    printf("         &按回车访问作者Github主页&\n");
    printf("          &按其余任意键返回主菜单&\n");
    IN_WHITE;
    printf("********************************************\n");
    do {
        if (getch() == '\r')
            openWeb("https://github.com/Voemp");    //打开作者Github主页
        else
            break;
    } while (1);
}

/*函数功能：用方向键选择菜单或者输入数字选择菜单
 * line：当前光标所在行数
 * deta：第一个选项所在行（行数从0开始计算）
 * upper, lower：选项的上下界所在行（上界为最后一个选项的行数，下界为第一个选项的行数）
 * (*P)(int)：函数指针，选择哪个覆盖菜单
 * 返回值：选择的选项（1~9）（引用时判断是否为已有选项，如果不是则重新选择）
 */
int menuController(int line, int deta, int lower, int upper, void (*p)(int)) {
    char c1, c2;
    setCursor(0, line);
    IN_CYAN;
    (*p)(line - deta + 1);
    setCursor(0, upper + 6);
    while ((c1 = getch()) != '\r') {
        if (c1 >= '0' && c1 <= '9') {   //如果输入的是数字，则直接返回
            setCursor(0, upper + 6);
            IN_WHITE;
            return c1 - '0';
        } else if (c1 == -32) {
            c2 = getch();
            if (c2 == DOWNKEY) {
                setCursor(0, line);
                IN_WHITE;    //恢复默认色
                (*p)(line - deta + 1);    //覆盖，实现退选
                if (line == upper)    //如果已经到了上界，则返回下界，实现滚动高亮
                    line = lower;
                else
                    ++line;    //行数+1
                setCursor(0, line);
                IN_CYAN;    //选择高亮色
                (*p)(line - deta + 1);    //覆盖，实现选中
            }
            if (c2 == UPKEY) {
                setCursor(0, line);
                IN_WHITE;    //恢复默认色
                (*p)(line - deta + 1);
                if (line == lower)    //如果已经到了下界，则返回上界，实现滚动高亮
                    line = upper;
                else
                    --line;    //行数-1
                setCursor(0, line);
                IN_CYAN;    //选择高亮色
                (*p)(line - deta + 1);
            }
            setCursor(0, upper + 6);
        }
    }
    setCursor(0, line);
    IN_BLUE;
    (*p)(line - deta + 1);
    IN_WHITE;
    setCursor(0, upper + 6);
    return line - deta + 1;
}