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

int g_subjectNum = 6;   //ȫ�ֱ��������ڴ洢��Ŀ����//���Դ����ļ��У���ʦ�����޸�
int g_studentNum = 0;   //ȫ�ֱ��������ڴ洢ѧ������
USER *g_user = NULL;    //ȫ�ֱ��������ڴ洢��ǰ��¼�û�����Ϣ
int login_status = 0;   //ȫ�ֱ��������ڴ洢��ǰ��¼״̬��0Ϊδ��¼��1Ϊ��¼

int main() {
    setTitle("V-SGMS 5.0");
    system("color f9");
    HWND window = GetConsoleWindow();
    SetWindowPos(window, NULL, 510, 330, 0, 0, SWP_NOSIZE);
    setWindowSize(479, 326);
    welcomeInit();    //��ӭ����
    setWindowSize(943, 598);
    readBasicInfo();    //��ȡ������Ϣ
    STU *head = NULL;   //ѧ����Ϣ����ͷָ��
    int choice1 = 0, choice2 = 0;   //���ڴ洢�û�ѡ��Ĳ˵�ѡ��
    int bonus = 0;  //���ڴ洢�ʵ���״̬
    while (1) {
        if (login_status == 0) {
            loginSystem();  //��¼ϵͳ
        } else if (login_status == 1) {
            //���˵�
            do {
                choice1 = menuController(mainMenu, 6);
                switch (choice1) {
                    case 0:
                        bonus += 1;
                        if (bonus == 1) {
                            printf("�ţ�");
                            Sleep(200);
                        } else if (bonus == 2) {
                            printf("���������ʲô������");
                            Sleep(200);
                        } else if (bonus == 3) {
                            printf("���㷢���ˣ�");
                            Sleep(200);
                        } else if (bonus == 4) {
                            printf("�ðȡ�");
                            Sleep(200);
                        }
                        if (bonus >= 5) {
                            printf("�����ǲʵ�ร�");
                            Sleep(500);
                            bonusScene();   //�ʵ�
                        }
                        break;
                    case 1: //ѧ���ɼ���ѯ
                        do {
                            if (g_user->role == 1) {    //��ʦ��¼
                                choice2 = menuController(studentGradeQueryMenu1, 9);
                                head = doubleListReadFromFile();
                                switch (choice2) {
                                    case 1: //��ѯÿ�ſγ̵��ֺܷ�ƽ����
                                        queryTotalAndAverageScore(head);
                                        break;
                                    case 2: //����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
                                        queryRankAscending(head);
                                        break;
                                    case 3: //����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
                                        queryRankDescending(head);
                                        break;
                                    case 4: //����ѧ����С�����ų��ɼ���
                                        queryRankID(head);
                                        break;
                                    case 5://��ѧ�Ų�ѯѧ������������ƿ��Գɼ�
                                        checkStudent(head, 1);
                                        break;
                                    case 6://��������ѯѧ������������ƿ��Գɼ�
                                        checkStudent(head, 2);
                                        break;
                                    case 7://ͳ�Ʋ�ͬ�����ε������ٷֱ�
                                        statisticalScores(head);
                                        break;
                                    case 8: //���ȫ����Ϣ
                                        printAll(head);
                                        break;
                                    case 9: //������һ���˵�
                                        break;
                                    default:
                                        printf("û�����ѡ�");
                                        Sleep(300);
                                        break;
                                }
                                if (choice2 != 9) { //������Ƿ�����һ���˵�������ͣ
                                    IN_REDWORD;
                                    printf("\n��ESC��������һ���˵�������");
                                    IN_WHITE;
                                    while (getch() != 27) {
                                        continue;
                                    }
                                    choice2 = 0;
                                }
                            } else if (g_user->role == 2) { //ѧ����¼
                                choice2 = menuController(studentGradeQueryMenu2, 2);
                                head = doubleListReadFromFile();
                                if (choice2 == 1) {
                                    checkMyScore(head);
                                    IN_REDWORD;
                                    printf("\n��ESC��������һ���˵�������");
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
                            choice1 = 0;    //������һ���˵�
                        } while (choice2 < 1 || choice2 > 9);
                        break;
                    case 2: //ѧ���ɼ�����
                        do {
                            if (g_user->role == 1)   //��ʦ��¼
                                choice2 = menuController(studentGradeManageMenu1, 4);
                            else if (g_user->role == 2)  //ѧ����¼
                                choice2 = menuController(studentGradeManageMenu2, 4);
                            head = doubleListReadFromFile();
                            switch (choice2) {
                                case 1: //¼��ѧ���ɼ�
                                    if (g_user->role == 1)   //��ʦ��¼
                                        readScoreInfinite(head);
                                    else if (g_user->role == 2)  //ѧ����¼
                                        readScoreOnce(head);
                                    break;
                                case 2: //�޸�ѧ���ɼ�
                                    if (g_user->role == 1)   //��ʦ��¼
                                        modifyScore1(head);
                                    else if (g_user->role == 2)  //ѧ����¼
                                        modifyScore2(head);
                                    break;
                                case 3: //ɾ��ѧ����Ϣ
                                    if (g_user->role == 1)   //��ʦ��¼
                                        deleteStudent1(head);
                                    else if (g_user->role == 2)  //ѧ����¼
                                        deleteStudent2(head);
                                    break;
                                case 4: //������һ���˵�
                                    break;
                                default:
                                    printf("û�����ѡ�");
                                    Sleep(300);
                                    break;
                            }
                            if (choice2 != 4) { //������Ƿ�����һ���˵�����ѭ��
                                choice2 = 0;
                            }
                            doubleListWriteToFile(head);
                            doubleListFree(head);
                            choice1 = 0;
                        } while (choice2 < 1 || choice2 > 4);
                        break;
                    case 3: //�˳���¼
                        logoutMod(g_user);
                        break;
                    case 4: //��Ŀ����
                        if (g_user->role == 1)   //��ʦ��¼
                            setSubjectNum();
                        else if (g_user->role == 2) {  //ѧ����¼
                            printf("��û��Ȩ�޽��д˲�����\n");
                            Sleep(800);
                        }
                        break;
                    case 5: //����
                        About();
                        choice1 = 0;
                        break;
                    case 6: //�˳�
                        choice2 = menuController(exitConfirmMenu, 2);
                        if (choice2 == 1) {
                            exit(0);
                        } else {
                            choice1 = 0;
                        }
                        break;
                    default:
                        printf("û�����ѡ�");
                        Sleep(300);
                        break;
                }
            } while (choice1 < 1 || choice1 > 6);
        }
    }
    return 0;
}