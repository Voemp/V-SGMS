#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Init.h"
#include "LoginSystem.h"
#include "struct.h"
#include "GradeManagement.h"
#include "StudentDoubleList.h"

int g_subjectNum = 0;   //全局变量，用于存储科目数量
int g_studentNum = 0;   //全局变量，用于存储学生数量
USER *g_user = NULL;    //全局变量，用于存储当前登录用户的信息

int main() {
    setTitle("V-SGMS 1.0");
    setWindowSize(479, 390);
    system("color f9");
    //welcomeInit();
    STU *head = doubleListCreate();

    USER *temp_user = (USER *) calloc(sizeof(USER), 1);
    loginMod(temp_user, 6, 3);
    /*int choice1, choice2;
    do {
        mainMenu();
        choice1 = menuController(3, 3, 3, 8, coverMainMenu);
        switch (choice1) {
            case 0:
                printf("这是个小彩蛋，嘻嘻！");
                Sleep(500);
                break;
            case 1:
                do {
                    studentGradeQueryMenu1();
                    choice2 = menuController(3, 3, 3, 10, coverStudentGradeQueryMenu1);
                    switch (choice2) {
                        case 1:
                            printf("1");
                            break;
                        case 2:
                            printf("2");
                            break;
                        case 3:
                            printf("3");
                            break;
                        case 4:
                            printf("4");
                            break;
                        case 5:
                            printf("5");
                            break;
                        case 6:
                            printf("6");
                            break;
                        case 7:
                            printf("7");
                            break;
                        case 8:
                            choice1 = 0;
                            break;
                        default:
                            printf("没有这个选项！");
                            Sleep(300);
                            break;
                    }
                } while (choice2 < 1 || choice2 > 8);
                break;
            case 2:
                do {
                    studentGradeManageMenu1();
                    choice2 = menuController(3, 3, 3, 6, coverStudentGradeManageMenu1);
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
                            choice1 = 0;
                            break;
                        default:
                            printf("没有这个选项！");
                            Sleep(300);
                            break;
                    }
                } while (choice2 < 1 || choice2 > 4);
                break;
            case 3:
                printf("3");
                break;
            case 4:
                printf("4");
                break;
            case 5:
                exitConfirmMenu();
                choice1 = menuController(3, 3, 3, 4, coverExitConfirmMenu);
                if (choice1 == 1) {
                    exit(0);
                } else {
                    choice1 = 0;
                }
                break;
            case 6:
                About();
                choice1 = 0;
                break;
            default:
                printf("没有这个选项！");
                Sleep(300);
                break;
        }
    } while (choice1 < 1 || choice1 > 6);
    */
    system("pause");
    return 0;
}
