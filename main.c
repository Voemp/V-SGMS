#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Init.h"
#include "LoginSystem.h"
#include "struct.h"
#include "GradeManagement.h"
#include "StudentDoubleList.h"

int g_subjectNum = 6;   //全局变量，用于存储科目数量
int g_studentNum = 0;   //全局变量，用于存储学生数量
USER *g_user = NULL;    //全局变量，用于存储当前登录用户的信息

int main() {
    setTitle("V-SGMS 1.0");
    //setWindowSize(479, 390);
    system("color f9");
    //welcomeInit();
    STU *head = doubleListReadFromFile();    //从文件读取学生信息

    //USER *temp_user = (USER *) calloc(sizeof(USER), 1);
    //loginMod(temp_user, 6, 3);
    int choice1, choice2;
    do {
        choice1 = menuController(mainMenu, 6);
        switch (choice1) {
            case 0:
                printf("这是个小彩蛋，嘻嘻！");
                Sleep(500);
                break;
            case 1: //学生成绩查询
                do {
                    choice2 = menuController(studentGradeQueryMenu1, 8);
                    switch (choice2) {
                        case 1: //查询每门课程的总分和平均分
                            printf("1");
                            break;
                        case 2: //按照每个学生的总分由高到低排出名次表
                            printf("2");
                            break;
                        case 3: //按照每个学生的总分由高到低排出名次表
                            printf("3");
                            break;
                        case 4: //按照学号由小到大排出成绩表
                            printf("4");
                            break;
                        case 5:
                            printf("5");
                            break;
                        case 6:
                            printf("6");
                            break;
                        case 7: //输出每个学生全部信息
                            system("cls");
                            doubleListPrint(head);
                            break;
                        case 8:
                            break;
                        default:
                            printf("没有这个选项！");
                            Sleep(300);
                            break;
                    }
                    getch();
                    choice1 = 0;
                } while (choice2 < 1 || choice2 > 8);
                break;
            case 2: //学生成绩管理
                do {
                    choice2 = menuController(studentGradeManageMenu1, 4);
                    switch (choice2) {
                        case 1:
                            readScoreInfinite(head);
                            choice2 = 0;
                            break;
                        case 2:
                            printf("2");
                            break;
                        case 3:
                            printf("3");
                            break;
                        case 4:
                            break;
                        default:
                            printf("没有这个选项！");
                            Sleep(300);
                            break;
                    }
                    getch();
                    choice1 = 0;
                    doubleListWriteToFile(head);
                } while (choice2 < 1 || choice2 > 4);
                break;
            case 3: //修改密码
                printf("3");
                break;
            case 4: //退出登录
                printf("4");
                break;
            case 5: //关于
                About();
                choice1 = 0;
                break;
            case 6: //退出
                choice2 = menuController(exitConfirmMenu, 2);
                if (choice2 == 1) {
                    exit(0);
                } else {
                    choice1 = 0;
                }
                break;
            default:
                printf("没有这个选项！");
                Sleep(300);
                break;
        }
    } while (choice1 < 1 || choice1 > 6);
    system("pause");
    return 0;
}
