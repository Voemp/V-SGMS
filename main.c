#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Init.h"
#include "LoginSystem.h"
#include "GradeManagement.h"
#include "StudentDoubleList.h"
#include "FunctionLib.h"

#define IN_REDWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfc)
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)

int g_subjectNum = 6;   //全局变量，用于存储科目数量//可以存在文件中，老师可以修改
int g_studentNum = 0;   //全局变量，用于存储学生数量
USER *g_user = NULL;    //全局变量，用于存储当前登录用户的信息
int login_status = 0;   //全局变量，用于存储当前登录状态，0为未登录，1为登录

int main() {
    setTitle("V-SGMS 5.0");
    system("color f9");
    HWND window = GetConsoleWindow();
    SetWindowPos(window, NULL, 510, 330, 0, 0, SWP_NOSIZE);
    setWindowSize(479, 326);
    welcomeInit();    //欢迎界面
    setWindowSize(943, 598);
    readBasicInfo();    //读取基本信息
    STU *head = NULL;   //学生信息链表头指针
    int choice1 = 0, choice2 = 0;   //用于存储用户选择的菜单选项
    int bonus = 0;  //用于存储彩蛋的状态
    while (1) {
        if (login_status == 0) {
            loginSystem();  //登录系统
        } else if (login_status == 1) {
            //主菜单
            do {
                choice1 = menuController(mainMenu, 6);
                switch (choice1) {
                    case 0:
                        bonus += 1;
                        if (bonus == 1) {
                            printf("嗯？");
                            Sleep(200);
                        } else if (bonus == 2) {
                            printf("你好像在找什么东西。");
                            Sleep(200);
                        } else if (bonus == 3) {
                            printf("被你发现了！");
                            Sleep(200);
                        } else if (bonus == 4) {
                            printf("好叭。");
                            Sleep(200);
                        }
                        if (bonus >= 5) {
                            printf("这里是彩蛋喔！");
                            Sleep(500);
                            bonusScene();   //彩蛋
                        }
                        break;
                    case 1: //学生成绩查询
                        do {
                            if (g_user->role == 1) {    //老师登录
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
                            } else if (g_user->role == 2) { //学生登录
                                choice2 = menuController(studentGradeQueryMenu2, 2);
                                head = doubleListReadFromFile();
                                if (choice2 == 1) {
                                    checkMyScore(head);
                                    IN_REDWORD;
                                    printf("\n按ESC键返回上一级菜单。。。");
                                    IN_WHITE;
                                    while (getch() != 27) {
                                        continue;
                                    }
                                    choice2 = 0;
                                } else if (choice2 == 2) {
                                    choice2 = 9;
                                }
                            }
                            doubleListFree(head);
                            choice1 = 0;    //返回上一级菜单
                        } while (choice2 < 1 || choice2 > 9);
                        break;
                    case 2: //学生成绩管理
                        do {
                            if (g_user->role == 1)   //老师登录
                                choice2 = menuController(studentGradeManageMenu1, 4);
                            else if (g_user->role == 2)  //学生登录
                                choice2 = menuController(studentGradeManageMenu2, 4);
                            head = doubleListReadFromFile();
                            switch (choice2) {
                                case 1: //录入学生成绩
                                    if (g_user->role == 1)   //老师登录
                                        readScoreInfinite(head);
                                    else if (g_user->role == 2)  //学生登录
                                        readScoreOnce(head);
                                    break;
                                case 2: //修改学生成绩
                                    if (g_user->role == 1)   //老师登录
                                        modifyScore1(head);
                                    else if (g_user->role == 2)  //学生登录
                                        modifyScore2(head);
                                    break;
                                case 3: //删除学生信息
                                    if (g_user->role == 1)   //老师登录
                                        deleteStudent1(head);
                                    else if (g_user->role == 2)  //学生登录
                                        deleteStudent2(head);
                                    break;
                                case 4: //返回上一级菜单
                                    break;
                                default:
                                    printf("没有这个选项！");
                                    Sleep(300);
                                    break;
                            }
                            if (choice2 != 4) { //如果不是返回上一级菜单，就循环
                                choice2 = 0;
                            }
                            doubleListWriteToFile(head);
                            doubleListFree(head);
                            choice1 = 0;
                        } while (choice2 < 1 || choice2 > 4);
                        break;
                    case 3: //退出登录
                        logoutMod(g_user);
                        break;
                    case 4: //科目设置
                        if (g_user->role == 1)   //老师登录
                            setSubjectNum();
                        else if (g_user->role == 2) {  //学生登录
                            printf("你没有权限进行此操作！\n");
                            Sleep(800);
                        }
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
        }
    }
    return 0;
}