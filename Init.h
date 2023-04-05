// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_INIT_H
#define V_SGMS_INIT_H

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
void welcomeInit();

//��¼��������
extern char *loginMenu[7];

//���˵�����
extern char *mainMenu[10];

//ѧ���ɼ���ѯ�˵�����ʦ�棩����
extern char *studentGradeQueryMenu1[12];

//ѧ���ɼ������������
extern char *studentGradeManageMenu1[8];

//�˳�����ȷ�Ͻ�������
extern char *exitConfirmMenu[6];

//�������ܣ����ڽ���
void About();


/*�������ܣ����Ʋ˵�
 * **menu��ѡ���ĸ����ǲ˵�
 * RowSize���˵�������
 * line�����������
 * confirm���Ƿ�ȷ��
 */
void drawMenu(char *menu[], int RowSize, int line, int confirm);

/*�������ܣ��÷����ѡ��˵�������������ѡ��˵�
 * upper, lower��ѡ������½������У��Ͻ�Ϊ���һ��ѡ����������½�Ϊ��һ��ѡ���������
 * **menu��ѡ���ĸ����ǲ˵�
 * ����ֵ��ѡ���ѡ�1~9��������ʱ�ж��Ƿ�Ϊ����ѡ��������������ѡ��
 */
int menuController(char *menu[], int lower, int upper);

#endif //V_SGMS_INIT_H
