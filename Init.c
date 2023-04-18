// Created by VoidEmpty on 2023/3/29.
#include "Init.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "FunctionLib.h"

#define IN_BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x90)
#define IN_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xb0)
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)
#define IN_REDWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfc)
#define IN_CYANWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfb)

#define TEMPKEY -32
#define UPKEY 72
#define DOWNKEY 80

//�������ܣ���ӡ��ӭ����
void welcomeInit() {
    system("cls");
    printf("****************************************************\n");
    printf(" VV        VV          SSSS    GGGG   M   M   SSSS  \n");
    printf(" VV       VV          S       G    G  MM MM  S      \n");
    printf(" VV      VV           S       G       MM MM  S      \n");
    printf(" VV     VV     =====   SSSS   G       M M M   SSSS  \n");
    printf(" VV    VV                  S  G   GG  M   M       S \n");
    printf(" VV   VV                   S  G    G  M   M       S \n");
    printf("  VVV                  SSSS    GGGG   M   M   SSSS  \n");
    printf("****************************************************\n");
    printf("          ��ӭʹ��V-SIMSѧ���ɼ�����ϵͳ��           \n");
    printf("****************************************************\n");
    printf("               ���ߣ�VoidEmpty\n");
    printf("****************************************************\n");
    IN_CYANWORD;
    printf("�������ڼ�����[��������������������]0%\r");
    Sleep(300);
    printf("�������ڼ�����[��������������������]20%\r");
    Sleep(300);
    printf("�������ڼ�����[��������������������]40%\r");
    Sleep(300);
    printf("�������ڼ�����[��������������������]60%\r");
    Sleep(300);
    printf("�������ڼ�����[��������������������]80%\r");
    Sleep(300);
    printf("�������ڼ�����[��������������������]100%\n");
    Sleep(300);
    printf("���������ɣ�\n");
    IN_WHITE;
    Sleep(400);
}

//��¼����
char *loginMenu[7] = {"********************************\0",
                      "*           ��¼ϵͳ           *\0",
                      "********************************\0",
                      "*        1.��¼�����ʺ�        *\0",
                      "*        2.ע���µ��ʺ�        *\0",
                      "*        3.�˳�����            *\0",
                      "********************************\0"};

//���˵�
char *mainMenu[10] = {"********************************\0",
                      "*           ���˵�             *\0",
                      "********************************\0",
                      "*        1.ѧ���ɼ���ѯ        *\0",
                      "*        2.ѧ���ɼ�����        *\0",
                      "*        3.�˳���¼            *\0",
                      "*        4.��Ŀ����            *\0",
                      "*        5.����                *\0",
                      "*        6.�˳�����(ESC)       *\0",
                      "********************************\0"};

//ѧ���ɼ���ѯ�˵�����ʦ�棩
char *studentGradeQueryMenu1[13] = {"******************************************************\0",
                                    "*                ѧ���ɼ���ѯ����ʦ�棩              *\0",
                                    "******************************************************\0",
                                    "*        1.��ѯÿ�ſγ̵��ֺܷ�ƽ����                *\0",
                                    "*        2.����ÿ��ѧ�����ܷ��ɸߵ����ų����α�      *\0",
                                    "*        3.����ÿ��ѧ�����ܷ��ɵ͵����ų����α�      *\0",
                                    "*        4.����ѧ����С�����ų��ɼ���                *\0",
                                    "*        5.����ѧ�Ų�ѯѧ������������ƿ��Գɼ�      *\0",
                                    "*        6.����������ѯѧ������������ƿ��Գɼ�      *\0",
                                    "*        7.ͳ�Ʋ�ͬ�����ε������ٷֱ�                *\0",
                                    "*        8.���ȫ����Ϣ                              *\0",
                                    "*        9.�������˵�                                *\0",
                                    "******************************************************\0"};

//ѧ���ɼ���ѯ�˵���ѧ���棩
char *studentGradeQueryMenu2[6] = {"*********************************\0",
                                   "*     ѧ���ɼ���ѯ��ѧ���棩    *\0",
                                   "*********************************\0",
                                   "*       1.��ѯ�Լ��ĳɼ�        *\0",
                                   "*       2.�������˵�            *\0",
                                   "*********************************\0"};

//ѧ���ɼ�����˵�����ʦ�棩
char *studentGradeManageMenu1[8] = {"*********************************\0",
                                    "*     ѧ���ɼ�������ʦ�棩    *\0",
                                    "*********************************\0",
                                    "*       1.���ѧ���ɼ�          *\0",
                                    "*       2.�޸�ѧ���ɼ�          *\0",
                                    "*       3.ɾ��ѧ����Ϣ          *\0",
                                    "*       4.�������˵�            *\0",
                                    "*********************************\0"};

//ѧ���ɼ�����˵���ѧ���棩
char *studentGradeManageMenu2[8] = {"*********************************\0",
                                    "*     ѧ���ɼ�����ѧ���棩    *\0",
                                    "*********************************\0",
                                    "*       1.¼���Լ��ĳɼ�        *\0",
                                    "*       2.�޸��Լ��ĳɼ�        *\0",
                                    "*       3.ɾ���Լ��ĳɼ�        *\0",
                                    "*       4.�������˵�            *\0",
                                    "*********************************\0"};

//�˳�����ȷ�Ͻ���
char *exitConfirmMenu[6] = {"********************************\0",
                            "*           �˳�����           *\0",
                            "********************************\0",
                            "*        1.ȷ���˳�����        *\0",
                            "*        2.������һ��          *\0",
                            "********************************\0"};

//�������ܣ����ڽ���
void About() {
    system("cls");
    printf("********************************************\n");
    printf("*                   ����                   *\n");
    printf("********************************************\n");
    printf("*    Void-StudentGradeManagementSystem     *\n");
    printf("********************************************\n");
    printf("*             ���ߣ�VoidEmpty              *\n");
    printf("*             �汾��1.0                    *\n");
    printf("*             ���ڣ�2023.04.01             *\n");
    printf("*����Github��");
    IN_CYANWORD;
    printf("https://github.com/Voemp");
    IN_WHITE;
    printf("      *\n");
    printf("*��Ŀ��ַ��https://github.com/Voemp/V-SGMS *\n");
    printf("********************************************\n");
    IN_REDWORD;
    printf("         &���س���������Github��ҳ&\n");
    printf("          &������������������˵�&\n");
    IN_WHITE;
    printf("********************************************\n");
    do {
        if (getch() == '\r')
            openWeb("https://github.com/Voemp");    //������Github��ҳ
        else
            break;
    } while (1);
}

/*�������ܣ����Ʋ˵�
 * **menu��ѡ���ĸ����ǲ˵�
 * RowSize���˵�������
 * line�����������
 * confirm���Ƿ�ȷ��
 */
void drawMenu(char *menu[], int RowSize, int line, int confirm) {
    setCursor(0, 0);    //������ƶ������Ͻ�
    //int LineSize = strlen((char *) menu) + 1;   //����ÿһ�еĳ���
    for (int i = 0; i < RowSize; ++i) {
        if (i == line) {
            if (confirm == 0) {
                IN_CYAN;
                printf("%s\n", menu[i]);
            } else {
                IN_BLUE;
                printf("%s\n", menu[i]);
            }
            IN_WHITE;
        } else {
            printf("%s\n", menu[i]);
        }
    }
    IN_REDWORD;
    printf("��ʹ�á�������enter��ʵ��ѡ���ִ������\n");
    printf("��������ÿ������ǰ���������ִ������\n");
    printf("��ESC��������һ��\n");
    IN_WHITE;
    printf("%s\n\n", menu[0]);
}


/*�������ܣ��÷����ѡ��˵�������������ѡ��˵�
 * **menu��ѡ���ĸ����ǲ˵�
 * choice_num���˵�ѡ��ĸ���
 * ����ֵ��ѡ���ѡ�1~9��������ʱ�ж��Ƿ�Ϊ����ѡ��������������ѡ��
 */
int menuController(char *menu[], int choice_num) {
    system("cls");
    //lowerΪ��һ��ѡ���������upperΪ���һ��ѡ�������, lineΪ���������
    int confirm = 0, lower = 3, upper = lower + choice_num - 1, line = lower;
    drawMenu(menu, upper + 2, line, confirm);   //���Ʋ˵�
    char c1, c2;
    while ((c1 = getch()) != '\r') {
        if (c1 == 27) { //����������ESC��
            return choice_num;
        } else if (c1 >= '0' && c1 <= '9') {   //�������������֣���ֱ�ӷ���
            return c1 - '0';
        } else if (c1 == -32) {  //���������Ƿ����
            c2 = getch();
            if (c2 == DOWNKEY) {    //�����������·����
                if (line == upper) line = lower - 1;
                drawMenu(menu, upper + 2, ++line, confirm);
            }
            if (c2 == UPKEY) {  //�����������Ϸ����
                if (line == lower) line = upper + 1;
                drawMenu(menu, upper + 2, --line, confirm);
            }
        }
    }
    confirm = 1;
    drawMenu(menu, upper + 2, line, confirm);
    Sleep(80);
    return line - lower + 1;
}