#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Init.h"
#include "LoginSystem.h"
#include "struct.h"

int g_subjectNum = 0;   //ȫ�ֱ��������ڴ洢��Ŀ����
USER *g_user = NULL;    //ȫ�ֱ��������ڴ洢��ǰ��¼�û�����Ϣ

int main() {
    SetTitle("V-SGMS 1.0");
    system("color f9");
    //welcomeInit();
    //USER *temp_user = (USER *) malloc(sizeof(USER));
    //loginMod(temp_user, 6, 3);
    int choice;
    do {
        mainMenu();
        choice = menuController(3, 3, 3, 8, coverMainMenu);
        switch (choice) {
            case 0:
                printf("���Ǹ�С�ʵ���������");
                Sleep(500);
                break;
            case 1:
                do {
                    studentGradeQueryMenu1();
                    choice = menuController(3, 3, 3, 10, coverStudentGradeQueryMenu1);
                    switch (choice) {
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
                            break;
                        default:
                            printf("û�����ѡ�");
                            Sleep(300);
                            break;
                    }
                } while (choice < 1 || choice > 8);
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
                exitConfirmMenu();
                choice = menuController(3, 3, 3, 4, coverExitConfirmMenu);
                if (choice == 1) {
                    exit(0);
                } else {
                    choice = 0;
                }
                break;
            case 6:
                About();
                choice = 0;
                break;
            default:
                printf("û�����ѡ�");
                Sleep(300);
                break;
        }
    } while (choice < 1 || choice > 6);
    system("pause");
    return 0;
}
