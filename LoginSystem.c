// Created by VoidEmpty on 2023/3/29.
#include "LoginSystem.h"

//函数功能：登录模块
int loginMod(USER *temp_user, int x, int y) {
    USER local_user;
    int temp = 1;
    int i = 0, j = 0;    //定义循环变量
    short temp_y;
    char ch;
    system("cls");
    printf("********************\n");
    printf("*       登录       *\n");
    printf("********************\n");
    printf("帐号：\n");
    printf("密码：\n");
    setCursor(x, y);    //将光标移动到“帐号：”处
    do {
        if (getCursor().X > x + 20) {   //如果字符数超过20个，则禁止输入
            printf("\b \b");
            if (getCursor().Y == y) {
                i--;
                temp_user->account[i] = '\0';
                setCursor(0, y + 3);
                printf("帐号长度不能超过20个字符！\r");
                Sleep(500);
                printf("                          ");
                setCursor(x + 20, y);
            } else if (getCursor().Y == y + 1) {
                j--;
                temp_user->password[j] = '\0';
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
            temp_user->account[i] = ch;    //将键盘输入的字符存入帐号中
        } else if (pos.Y == y + 1) {  //如果光标在“密码：”处
            temp_user->password[j] = ch;    //将键盘输入的字符存入密码中
        } else {
            break;  //如果光标不在“帐号：”或“密码：”处，则退出循环
        }
        if (ch == '\r') {    //判断是否为回车键
            if (pos.Y == y) {   //如果光标在“帐号：”处
                temp_user->account[i] = '\0';    //将帐号的最后一个字符设为'\0'
                setCursor(x + j, y + 1);    //将光标移动到“密码：”处
            } else if (pos.Y == y + 1) {  //如果光标在“密码：”处
                temp_user->password[j] = '\0';    //将密码的最后一个字符设为'\0'
                break;  //退出循环
            }
        } else if (ch == TEMPKEY) {    //判断是否为方向键
            ch = getch();
            if (ch == UPKEY) {    //判断是否为向上键
                if (pos.Y == y + 1) {  //如果光标在“密码：”处
                    temp_user->password[j] = '\0';    //将密码的最后一个字符设为'\0'
                    setCursor(x + i, y);    //将光标移动到“帐号：”处
                } else if (pos.Y == y) {   //如果光标在“帐号：”处
                    temp_user->account[i] = '\0';    //将帐号的最后一个字符设为'\0'
                }
            } else if (ch == DOWNKEY) {    //判断是否为向下键
                if (pos.Y == y) {   //如果光标在“帐号：”处
                    temp_user->account[i] = '\0';    //将帐号的最后一个字符设为'\0'
                    setCursor(x + j, y + 1);    //将光标移动到“密码：”处
                } else if (pos.Y == y + 1) {  //如果光标在“密码：”处
                    temp_user->password[j] = '\0';    //将密码的最后一个字符设为'\0'
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
    FILE *fp;
    if ((fp = fopen("user.txt", "rb")) == NULL) {    //判断文件是否打开成功
        printf("文件打开失败！\n");
        Sleep(1000);
        exit(0);
    }
    fread(&local_user, sizeof(USER), 1, fp);    //读取文件中的用户信息
    while (1) {
        if (strcmp(temp_user->account, local_user.account) == 0 &&
            strcmp(temp_user->password, local_user.password) == 0) {    //判断帐号和密码是否正确
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
    Sleep(1000);
    return temp;
}