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

int g_subjectNum = 6;   //ȫ�ֱ��������ڴ洢��Ŀ����//���Դ����ļ��У���ʦ�����޸ģ��޸ĺ���������
int g_studentNum = 0;   //ȫ�ֱ��������ڴ洢ѧ������
USER *g_user = NULL;    //ȫ�ֱ��������ڴ洢��ǰ��¼�û�����Ϣ

int main() {
    setTitle("V-SGMS 1.0");
    //setWindowSize(479, 390);
    system("color f9");

    //welcomeInit();    //��ӭ����
    readBasicInfo();    //��ȡ������Ϣ
    STU *head = NULL;   //ѧ����Ϣ����ͷָ��

    //��¼����
    USER *temp_user = NULL; //������ʱ�洢��¼�û�����Ϣ
    int login_choice = 0;   //���ڴ洢��¼�˵�ѡ��
    do {
        temp_user = (USER *) calloc(sizeof(USER), 1);
        if (temp_user == NULL) {
            printf("�ڴ����ʧ�ܣ�\n");
            exit(0);
        }
        login_choice = menuController(loginMenu, 3);
        switch (login_choice) {
            case 1: //��¼�����ʺ�
                if (loginMod(temp_user) == 1) {
                    g_user = temp_user;
                    break;
                } else {
                    free(temp_user);
                    login_choice = 0;
                }
                break;
            case 2: //ע���µ��ʺ�
                //g_user = registerMod();
                break;
            case 3: //�˳�����
                login_choice = menuController(exitConfirmMenu, 2);
                if (login_choice == 1) {
                    exit(0);
                } else {
                    login_choice = 0;
                }
                break;
        }
    } while (login_choice < 1 || login_choice > 3);


    int choice1 = 0, choice2 = 0;   //���ڴ洢�û�ѡ��Ĳ˵�ѡ��
    //���˵�
    do {
        choice1 = menuController(mainMenu, 6);
        switch (choice1) {
            case 0:
                printf("���Ǹ�С�ʵ���������");
                Sleep(500);
                break;
            case 1: //ѧ���ɼ���ѯ
                do {
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
                    choice1 = 0;    //������һ���˵�
                    doubleListFree(head);
                } while (choice2 < 1 || choice2 > 9);
                break;
            case 2: //ѧ���ɼ�����
                do {
                    choice2 = menuController(studentGradeManageMenu1, 4);
                    head = doubleListReadFromFile();
                    switch (choice2) {
                        case 1: //¼��ѧ���ɼ�
                            readScoreInfinite(head);
                            choice2 = -1;
                            break;
                        case 2: //�޸�ѧ���ɼ�
                            modifyScore(head);
                            break;
                        case 3: //ɾ��ѧ����Ϣ
                            deleteStudent(head);
                            break;
                        case 4:
                            choice1 = 0;
                            break;
                        default:
                            printf("û�����ѡ�");
                            Sleep(300);
                            break;
                    }
                    doubleListWriteToFile(head);
                    doubleListFree(head);
                    choice1 = 0;
                } while (choice2 < 1 || choice2 > 4);
                break;
            case 3: //�˳���¼
                printf("3");
                break;
            case 4: //��Ŀ����
                printf("4");
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
    system("pause");
    return 0;
}
