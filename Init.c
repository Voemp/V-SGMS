// Created by VoidEmpty on 2023/3/29.
#include "Init.h"

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

//�������ܣ���ӡ��¼����
void loginMenu() {
    system("cls");
    printf("********************************\n");
    printf("*           ��¼ϵͳ           *\n");
    printf("********************************\n");
    printf("*        1.��¼�����ʺ�        *\n");
    printf("*        2.ע���µ��ʺ�        *\n");
    printf("*        3.�˳�����            *\n");
    printf("********************************\n");
}

//�������ܣ���ӡ���˵�����
void mainMenu() {
    system("cls");
    printf("********************************\n");
    printf("*           ���˵�             *\n");
    printf("********************************\n");
    printf("*        1.ѧ���ɼ���ѯ        *\n");
    printf("*        2.ѧ���ɼ�����        *\n");
    printf("*        3.�޸�����            *\n");
    printf("*        4.�˳���¼            *\n");
    printf("*        5.�˳�����            *\n");
    printf("*        6.����                *\n");
    printf("********************************\n");
    IN_REDWORD;
    printf("��ʹ�á�������enter��ʵ��ѡ���ִ������\n");
    printf("��������ÿ������ǰ���������ִ������\n");
    IN_WHITE;
    printf("********************************\n");
}

//�������ܣ��������˵�����
void coverMainMenu(int x) {
    switch (x) {
        case 1:
            printf("*        1.ѧ���ɼ���ѯ        *\n");
            break;
        case 2:
            printf("*        2.ѧ���ɼ�����        *\n");
            break;
        case 3:
            printf("*        3.�޸�����            *\n");
            break;
        case 4:
            printf("*        4.�˳���¼            *\n");
            break;
        case 5:
            printf("*        5.�˳�����            *\n");
            break;
        case 6:
            printf("*        6.����                *\n");
            break;
        default:
            break;
    }
}

//�������ܣ��˳�����ȷ�Ͻ���
void exitConfirmMenu() {
    system("cls");
    printf("********************************\n");
    printf("*           �˳�����           *\n");
    printf("********************************\n");
    printf("*        1.ȷ���˳�����        *\n");
    printf("*        2.�������˵�          *\n");
    printf("********************************\n");
    IN_REDWORD;
    printf("��ʹ�á�������enter��ʵ��ѡ���ִ������\n");
    printf("��������ÿ������ǰ���������ִ������\n");
    IN_WHITE;
    printf("********************************\n");
}

//�������ܣ������˳�����ȷ��
void coverExitConfirmMenu(int x) {
    switch (x) {
        case 1:
            printf("*        1.ȷ���˳�����        *\n");
            break;
        case 2:
            printf("*        2.�������˵�          *\n");
            break;
        default:
            break;
    }
}

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
    printf("*             ����Github��                 *\n");
    IN_CYANWORD;
    printf("*         https://github.com/Voemp         *\n");
    IN_WHITE;
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

/*�������ܣ��÷����ѡ��˵�������������ѡ��˵�
 * line����ǰ�����������
 * deta����һ��ѡ�������У�������0��ʼ���㣩
 * upper, lower��ѡ������½������У��Ͻ�Ϊ���һ��ѡ����������½�Ϊ��һ��ѡ���������
 * (*P)(int)������ָ�룬ѡ���ĸ����ǲ˵�
 * ����ֵ��ѡ���ѡ�1~9��������ʱ�ж��Ƿ�Ϊ����ѡ��������������ѡ��
 */
int menuController(int line, int deta, int lower, int upper, void (*p)(int)) {
    char c1, c2;
    setCursor(0, line);
    IN_CYAN;
    (*p)(line - deta + 1);
    setCursor(0, upper + 6);
    while ((c1 = getch()) != '\r') {
        if (c1 >= '0' && c1 <= '9') {   //�������������֣���ֱ�ӷ���
            setCursor(0, upper + 6);
            IN_WHITE;
            return c1 - '0';
        } else if (c1 == -32) {
            c2 = getch();
            if (c2 == DOWNKEY) {
                setCursor(0, line);
                IN_WHITE;    //�ָ�Ĭ��ɫ
                (*p)(line - deta + 1);    //���ǣ�ʵ����ѡ
                if (line == upper)    //����Ѿ������Ͻ磬�򷵻��½磬ʵ�ֹ�������
                    line = lower;
                else
                    ++line;    //����+1
                setCursor(0, line);
                IN_CYAN;    //ѡ�����ɫ
                (*p)(line - deta + 1);    //���ǣ�ʵ��ѡ��
            }
            if (c2 == UPKEY) {
                setCursor(0, line);
                IN_WHITE;    //�ָ�Ĭ��ɫ
                (*p)(line - deta + 1);
                if (line == lower)    //����Ѿ������½磬�򷵻��Ͻ磬ʵ�ֹ�������
                    line = upper;
                else
                    --line;    //����-1
                setCursor(0, line);
                IN_CYAN;    //ѡ�����ɫ
                (*p)(line - deta + 1);
            }
            setCursor(0, upper + 6);
        }
    }
    setCursor(0, line);
    IN_BLUE;
    (*p)(line - deta + 1);
    IN_WHITE;
    setCursor(0, upper + 6);
    return line - deta + 1;
}