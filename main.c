#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Init.h"
#include "LoginSystem.h"
#include "struct.h"
#include "GradeManagement.h"
#include "StudentDoubleList.h"
#include "FunctionLib.h"

#define IN_REDWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfc)
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)

int g_subjectNum = 6;   //全局变量，用于存储科目数量//可以存在文件中，老师可以修改，修改后重启程序
int g_studentNum = 0;   //全局变量，用于存储学生数量
USER *g_user = NULL;    //全局变量，用于存储当前登录用户的信息

int main() {
    setTitle("V-SGMS 1.0");
    //setWindowSize(479, 390);
    system("color f9");

    //welcomeInit();    //欢迎界面
    readBasicInfo();    //读取基本信息
    STU *head = NULL;   //学生信息链表头指针

    //登录部分
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
                    break;
                } else {
                    free(temp_user);
                    login_choice = 0;
                }
                break;
            case 2: //注册新的帐号
                //g_user = registerMod();
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


    int choice1 = 0, choice2 = 0;   //用于存储用户选择的菜单选项
    //主菜单
    do {
        choice1 = menuController(mainMenu, 6);
        switch (choice1) {
            case 0:
                printf("这是个小彩蛋，嘻嘻！");
                Sleep(500);
                break;
            case 1: //学生成绩查询
                do {
                    choice2 = menuController(studentGradeQueryMenu1, 9);
                    head = doubleListReadFromFile();
                    switch (choice2) {
                        case 1: //查询每门课程的总分和平均分
                            queryTotalAndAverageScore(head);
                            break;
                        case 2: //按照每个学生的总分由高到低排出名次表
                            queryRankAscending(head);
                            break;
                        case 3: //按照每个学生的总分由高到低排出名次表
                            queryRankDescending(head);
                            break;
                        case 4: //按照学号由小到大排出成绩表
                            queryRankID(head);
                            break;
                        case 5://按学号查询学生排名及其各科考试成绩
                            checkStudent(head, 1);
                            break;
                        case 6://按姓名查询学生排名及其各科考试成绩
                            checkStudent(head, 2);
                            break;
                        case 7://统计不同分数段的人数百分比
                            statisticalScores(head);
                            break;
                        case 8: //输出全部信息
                            printAll(head);
                            break;
                        case 9: //返回上一级菜单
                            break;
                        default:
                            printf("没有这个选项！");
                            Sleep(300);
                            break;
                    }
                    if (choice2 != 9) { //如果不是返回上一级菜单，就暂停
                        IN_REDWORD;
                        printf("\n按ESC键返回上一级菜单。。。");
                        IN_WHITE;
                        while (getch() != 27) {
                            continue;
                        }
                        choice2 = 0;
                    }
                    choice1 = 0;    //返回上一级菜单
                    doubleListFree(head);
                } while (choice2 < 1 || choice2 > 9);
                break;
            case 2: //学生成绩管理
                do {
                    choice2 = menuController(studentGradeManageMenu1, 4);
                    head = doubleListReadFromFile();
                    switch (choice2) {
                        case 1: //录入学生成绩
                            readScoreInfinite(head);
                            choice2 = -1;
                            break;
                        case 2: //修改学生成绩
                            modifyScore(head);
                            break;
                        case 3: //删除学生信息
                            deleteStudent(head);
                            break;
                        case 4:
                            choice1 = 0;
                            break;
                        default:
                            printf("没有这个选项！");
                            Sleep(300);
                            break;
                    }
                    doubleListWriteToFile(head);
                    doubleListFree(head);
                    choice1 = 0;
                } while (choice2 < 1 || choice2 > 4);
                break;
            case 3: //退出登录
                printf("3");
                break;
            case 4: //科目设置
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
