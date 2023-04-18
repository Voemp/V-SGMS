// Created by VoidEmpty on 2023/3/29.
#include "LoginSystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "FunctionLib.h"
#include "Init.h"

#define ADMINKEY "230417"
#define TEMPKEY -32
#define UPKEY 72
#define DOWNKEY 80
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)
#define IN_REDWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfc)
#define IN_CYANWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfb)

//登录界面
void loginSystem() {
    USER *temp_user = NULL; //用于临时存储登录用户的信息
    int login_choice = 0;   //用于存储登录菜单选项
    do {
        temp_user = (USER *) calloc(sizeof(USER), 1);
        if (temp_user == NULL) {
            printf("内存分配失败！\n");
            exit(0);
        }
        login_choice = menuController(loginMenu, 3);
        switch (login_choice) {
            case 1: //登录已有帐号
                if (loginMod(temp_user) == 1) {
                    g_user = temp_user;
                    login_status = 1;   //登录状态改为已登录
                    break;
                } else {
                    free(temp_user);
                    login_choice = 0;
                }
                break;
            case 2: //注册新的帐号
                if (registerMod(temp_user) == 1) {
                    g_user = temp_user;
                    login_status = 1;   //登录状态改为已登录
                    break;
                }
                break;
            case 3: //退出程序
                login_choice = menuController(exitConfirmMenu, 2);
                if (login_choice == 1) {
                    exit(0);
                } else {
                    login_choice = 0;
                }
                break;
        }
    } while (login_choice < 1 || login_choice > 3);
}

/*函数功能：帐号和密码输入
 * 参数说明：user：用户结构体指针
 *          x：光标初始位置的横坐标
 *          y：光标初始位置的纵坐标
 */
void inputAccountAndPassword(USER *user, int x, int y) {
    printf("帐号：\n");
    printf("密码：\n");
    setCursor(x, y);    //将光标移动到“帐号：”处
    int i = 0, j = 0;    //定义循环变量
    short temp_y;   //定义临时变量，用于存储光标位置
    char ch;    //定义临时变量，用于存储键盘输入的字符
    do {
        if (getCursor().X > x + 20) {   //如果字符数超过20个，则禁止输入
            printf("\b \b");
            if (getCursor().Y == y) {
                i--;
                user->account[i] = '\0';
                setCursor(0, y + 3);
                printf("帐号长度不能超过20个字符！\r");
                Sleep(500);
                printf("                          ");
                setCursor(x + 20, y);
            } else if (getCursor().Y == y + 1) {
                j--;
                user->password[j] = '\0';
                setCursor(0, y + 3);
                printf("密码长度不能超过20个字符！\r");
                Sleep(500);
                printf("                          ");
                setCursor(x + 20, y + 1);
            }
        }
        ch = getch();    //getch()函数用于获取键盘输入的字符
        COORD pos = getCursor();    //获取光标位置
        temp_y = pos.Y;
        if (pos.Y == y) {   //如果光标在“帐号：”处
            user->account[i] = ch;    //将键盘输入的字符存入帐号中
        } else if (pos.Y == y + 1) {  //如果光标在“密码：”处
            user->password[j] = ch;    //将键盘输入的字符存入密码中
        } else {
            break;  //如果光标不在“帐号：”或“密码：”处，则退出循环
        }
        if (ch == '\r') {    //判断是否为回车键
            if (pos.Y == y) {   //如果光标在“帐号：”处
                user->account[i] = '\0';    //将帐号的最后一个字符设为'\0'
                setCursor(x + j, y + 1);    //将光标移动到“密码：”处
            } else if (pos.Y == y + 1) {  //如果光标在“密码：”处
                user->password[j] = '\0';    //将密码的最后一个字符设为'\0'
                break;  //退出循环
            }
        } else if (ch == TEMPKEY) {    //判断是否为方向键
            ch = getch();
            if (ch == UPKEY) {    //判断是否为向上键
                if (pos.Y == y + 1) {  //如果光标在“密码：”处
                    user->password[j] = '\0';    //将密码的最后一个字符设为'\0'
                    setCursor(x + i, y);    //将光标移动到“帐号：”处
                } else if (pos.Y == y) {   //如果光标在“帐号：”处
                    user->account[i] = '\0';    //将帐号的最后一个字符设为'\0'
                }
            } else if (ch == DOWNKEY) {    //判断是否为向下键
                if (pos.Y == y) {   //如果光标在“帐号：”处
                    user->account[i] = '\0';    //将帐号的最后一个字符设为'\0'
                    setCursor(x + j, y + 1);    //将光标移动到“密码：”处
                } else if (pos.Y == y + 1) {  //如果光标在“密码：”处
                    user->password[j] = '\0';    //将密码的最后一个字符设为'\0'
                }
            }
        } else if (ch == '\b') {    //判断是否为退格键
            if (pos.Y == y) {   //如果光标在“帐号：”处
                if (i > 0) {    //判断是否为第一个字符
                    i--;
                    printf("\b \b");
                }
            } else if (pos.Y == y + 1) {  //如果光标在“密码：”处
                if (j > 0) {    //判断是否为第一个字符
                    j--;
                    printf("\b \b");
                }
            }
        } else {    //如果不是回车键或退格键，则输出字符
            if (pos.Y == y) {    //如果光标在“帐号：”处
                if (ch >= '0' && ch <= '9') {
                    printf("%c", ch);
                    i++;
                } else {
                    setCursor(0, y + 3);
                    printf("帐号只能为数字！\r");
                    Sleep(300);
                    printf("                          ");
                    setCursor(x + i, y);
                }
            } else if (pos.Y == y + 1) {  //如果光标在“密码：”处
                if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch == '_' ||
                    ch == '@') {
                    printf("*");
                    j++;
                } else {
                    setCursor(0, y + 3);
                    printf("密码只能为数字、字母、下划线和@！\r");
                    Sleep(300);
                    printf("                                 ");
                    setCursor(x + j, y + 1);
                }
            }
        }
    } while (temp_y == y || temp_y == y + 1);    //如果光标在“帐号：”或“密码：”处，则继续循环
    setCursor(0, y + 3);    //将光标移动到“密码：”下面一行
}

//登录模块
int loginMod(USER *temp_user) {
    USER local_user;
    int temp = 1;
    system("cls");
    printf("********************\n");
    printf("*       登录       *\n");
    printf("********************\n");
    inputAccountAndPassword(temp_user, 6, 3);    //输入帐号和密码
    //判断文件是否存在，如果不存在，则创建文件
    FILE *tfp = fopen("user.txt", "ab");
    fclose(tfp);
    FILE *fp;
    if ((fp = fopen("user.txt", "rb")) == NULL) {    //判断文件是否打开成功
        printf("文件打开失败！\n");
        Sleep(1000);
        exit(0);
    }
    fread(&local_user, sizeof(USER), 1, fp);    //读取文件中的用户信息
    while (1) {
        if (strcmp(temp_user->account, "") == 0) {    //判断帐号是否为空
            printf("帐号或密码错误！\n");
            temp = 0;
            break;
        }
        if (strcmp(temp_user->account, local_user.account) == 0 &&
            strcmp(temp_user->password, local_user.password) == 0) {    //判断帐号和密码是否正确
            temp_user->role = local_user.role;    //将用户的角色赋值给temp_user
            printf("登录成功！\n");
            break;
        }
        if (!feof(fp)) {    //判断是否到达文件尾
            fread(&local_user, sizeof(USER), 1, fp);    //读取文件中的用户信息
        } else {
            printf("帐号或密码错误！\n");
            temp = 0;
            break;
        }
    }
    fclose(fp);    //关闭文件
    Sleep(500);
    return temp;
}

//注册模块
int registerMod(USER *temp_user) {
    int temp = 1;
    do {
        system("cls");
        printf("********************\n");
        printf("*       注册       *\n");
        printf("********************\n");
        setCursor(0, 6);
        IN_REDWORD;
        printf("学生请务必使用学号注册！");
        IN_WHITE;
        setCursor(0, 3);
        inputAccountAndPassword(temp_user, 6, 3);    //输入帐号和密码
        //验证管理员密钥
        char key[20], ch;
        IN_CYANWORD;
        printf("<如果想注册为教师，请输入管理员密钥>\n<如果想注册为学生，请直接按回车键>\n");
        IN_WHITE;
        do {
            printf("请输入管理员密钥：");
            do {
                ch = getch();
                if (ch == '\b') {
                    if (strlen(key) > 0) {
                        key[strlen(key) - 1] = '\0';
                        printf("\b \b");
                    }
                } else if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch == '_' ||
                           ch == '@') {
                    printf("*");
                    key[strlen(key)] = ch;
                }
            } while (ch != '\r');
            key[strlen(key)] = '\0';
            if (strlen(key) == 0) {
                temp_user->role = 2;    //将用户的角色设为学生
                printf("\n");   //换行
                break;
            } else if (strcmp(key, ADMINKEY) == 0) {
                temp_user->role = 1;    //将用户的角色设为教师
                printf("\n");   //换行
                break;
            } else {
                for (int i = strlen(key); i >= 0; i--) {  //清空key数组
                    key[i] = '\0';
                }
                printf("\r                              \r");
                IN_REDWORD;
                printf("管理员密钥错误！");
                IN_WHITE;
                Sleep(500);
                printf("\r                \r");
            }
        } while (strcmp(key, ADMINKEY) != 0);

        //判断文件是否存在，如果不存在，则创建文件
        FILE *tfp = fopen("user.txt", "ab");
        fclose(tfp);

        FILE *rfp;
        if ((rfp = fopen("user.txt", "rb")) == NULL) {    //判断文件是否打开成功
            printf("文件打开失败！\n");
            Sleep(1000);
            exit(0);
        }

        USER local_user;    //定义一个用户结构体变量
        fread(&local_user, sizeof(USER), 1, rfp);    //读取文件中的用户信息

        while (1) {
            if (strcmp(temp_user->account, local_user.account) == 0) {    //判断帐号是否已存在
                printf("帐号已存在！\n");
                Sleep(500);
                temp = 0;
                break;
            }
            if (!feof(rfp)) {    //判断是否到达文件尾
                fread(&local_user, sizeof(USER), 1, rfp);    //读取文件中的用户信息
            } else {
                temp = 1;
                break;
            }
        }
        fclose(rfp);    //关闭文件
    } while (temp == 0);    //如果帐号已存在，则继续循环

    FILE *wfp;
    if ((wfp = fopen("user.txt", "ab")) == NULL) {    //判断文件是否打开成功
        printf("文件打开失败！\n");
        Sleep(1000);
        exit(0);
    }
    fwrite(temp_user, sizeof(USER), 1, wfp);    //将用户信息写入文件
    fclose(wfp);    //关闭文件
    printf("注册成功！已自动登录。\n");
    Sleep(500);
    return temp;
}

//函数功能：退出登录
void logoutMod(USER *user) {
    system("cls");
    printf("********************\n");
    printf("*       退出       *\n");
    printf("********************\n");
    free(user);    //释放user指针
    login_status = 0;    //将登录状态设为未登录
    printf("退出成功！\n");
    Sleep(500);
}