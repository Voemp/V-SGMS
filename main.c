#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Init.h"
#include "LoginSystem.h"
#include "struct.h"
#include "GradeManagement.h"
#include "StudentDoubleList.h"

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
    //USER *temp_user = (USER *) calloc(sizeof(USER), 1);
    //loginMod(temp_user, 6, 3);

    int choice1, choice2;   //���ڴ洢�û�ѡ��Ĳ˵�ѡ��
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
                    choice2 = menuController(studentGradeQueryMenu1, 8);
                    head = doubleListReadFromFile();
                    switch (choice2) {
                        case 1: //��ѯÿ�ſγ̵��ֺܷ�ƽ����
                            queryTotalAndAverageScore(head);
                            break;
                        case 2: //����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
                            printf("2");
                            break;
                        case 3: //����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
                            printf("3");
                            break;
                        case 4: //����ѧ����С�����ų��ɼ���
                            printf("4");
                            break;
                        case 5:
                            printf("5");
                            break;
                        case 6:
                            printf("6");
                            break;
                        case 7: //���ÿ��ѧ��ȫ����Ϣ
                            system("cls");
                            doubleListPrint(head);
                            break;
                        case 8: //������һ���˵�
                            break;
                        default:
                            printf("û�����ѡ�");
                            Sleep(300);
                            break;
                    }
                    if (choice2 != 8) { //������Ƿ�����һ���˵�������ͣ
                        printf("�����������������");
                        getch();    //��ͣ
                    }
                    choice1 = 0;
                    doubleListFree(head);
                } while (choice2 < 1 || choice2 > 8);
                break;
            case 2: //ѧ���ɼ�����
                do {
                    choice2 = menuController(studentGradeManageMenu1, 4);
                    head = doubleListReadFromFile();
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
                            printf("û�����ѡ�");
                            Sleep(300);
                            break;
                    }
                    doubleListWriteToFile(head);
                    doubleListFree(head);
                } while (choice2 < 1 || choice2 > 4);
                break;
            case 3: //�޸�����
                printf("3");
                break;
            case 4: //�˳���¼
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
