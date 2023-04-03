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

//�������ܣ���ӡ��¼����
void loginMenu();

//�������ܣ���ӡ���˵�����
void mainMenu();

//�������ܣ��������˵�����
void coverMainMenu(int x);

/*�������ܣ��÷����ѡ��˵�������������ѡ��˵�
 * line����ǰ�����������
 * deta����һ��ѡ�������У�������0��ʼ���㣩
 * upper, lower��ѡ������½������У��Ͻ�Ϊ���һ��ѡ����������½�Ϊ��һ��ѡ���������
 * (*P)(int)������ָ�룬ѡ���ĸ����ǲ˵�
 * ����ֵ��ѡ���ѡ�1~9��������ʱ�ж��Ƿ�Ϊ����ѡ��������������ѡ��
 */
int menuController(int line, int deta, int lower, int upper, void (*p)(int));


//�������ܣ����ڽ���
void About();

#endif //V_SGMS_INIT_H
