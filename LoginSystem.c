// Created by VoidEmpty on 2023/3/29.
#include "LoginSystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "FunctionLib.h"
#include "Init.h"

#define ADMINKEY "230417"
#define TEMPKEY -32
#define UPKEY 72
#define DOWNKEY 80
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)
#define IN_REDWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfc)
#define IN_CYANWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfb)

//��¼����
void loginSystem() {
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
                    login_status = 1;   //��¼״̬��Ϊ�ѵ�¼
                    break;
                } else {
                    free(temp_user);
                    login_choice = 0;
                }
                break;
            case 2: //ע���µ��ʺ�
                if (registerMod(temp_user) == 1) {
                    g_user = temp_user;
                    login_status = 1;   //��¼״̬��Ϊ�ѵ�¼
                    break;
                }
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
}

/*�������ܣ��ʺź���������
 * ����˵����user���û��ṹ��ָ��
 *          x������ʼλ�õĺ�����
 *          y������ʼλ�õ�������
 */
void inputAccountAndPassword(USER *user, int x, int y) {
    printf("�ʺţ�\n");
    printf("���룺\n");
    setCursor(x, y);    //������ƶ������ʺţ�����
    int i = 0, j = 0;    //����ѭ������
    short temp_y;   //������ʱ���������ڴ洢���λ��
    char ch;    //������ʱ���������ڴ洢����������ַ�
    do {
        if (getCursor().X > x + 20) {   //����ַ�������20�������ֹ����
            printf("\b \b");
            if (getCursor().Y == y) {
                i--;
                user->account[i] = '\0';
                setCursor(0, y + 3);
                printf("�ʺų��Ȳ��ܳ���20���ַ���\r");
                Sleep(500);
                printf("                          ");
                setCursor(x + 20, y);
            } else if (getCursor().Y == y + 1) {
                j--;
                user->password[j] = '\0';
                setCursor(0, y + 3);
                printf("���볤�Ȳ��ܳ���20���ַ���\r");
                Sleep(500);
                printf("                          ");
                setCursor(x + 20, y + 1);
            }
        }
        ch = getch();    //getch()�������ڻ�ȡ����������ַ�
        COORD pos = getCursor();    //��ȡ���λ��
        temp_y = pos.Y;
        if (pos.Y == y) {   //�������ڡ��ʺţ�����
            user->account[i] = ch;    //������������ַ������ʺ���
        } else if (pos.Y == y + 1) {  //�������ڡ����룺����
            user->password[j] = ch;    //������������ַ�����������
        } else {
            break;  //�����겻�ڡ��ʺţ��������룺���������˳�ѭ��
        }
        if (ch == '\r') {    //�ж��Ƿ�Ϊ�س���
            if (pos.Y == y) {   //�������ڡ��ʺţ�����
                user->account[i] = '\0';    //���ʺŵ����һ���ַ���Ϊ'\0'
                setCursor(x + j, y + 1);    //������ƶ��������룺����
            } else if (pos.Y == y + 1) {  //�������ڡ����룺����
                user->password[j] = '\0';    //����������һ���ַ���Ϊ'\0'
                break;  //�˳�ѭ��
            }
        } else if (ch == TEMPKEY) {    //�ж��Ƿ�Ϊ�����
            ch = getch();
            if (ch == UPKEY) {    //�ж��Ƿ�Ϊ���ϼ�
                if (pos.Y == y + 1) {  //�������ڡ����룺����
                    user->password[j] = '\0';    //����������һ���ַ���Ϊ'\0'
                    setCursor(x + i, y);    //������ƶ������ʺţ�����
                } else if (pos.Y == y) {   //�������ڡ��ʺţ�����
                    user->account[i] = '\0';    //���ʺŵ����һ���ַ���Ϊ'\0'
                }
            } else if (ch == DOWNKEY) {    //�ж��Ƿ�Ϊ���¼�
                if (pos.Y == y) {   //�������ڡ��ʺţ�����
                    user->account[i] = '\0';    //���ʺŵ����һ���ַ���Ϊ'\0'
                    setCursor(x + j, y + 1);    //������ƶ��������룺����
                } else if (pos.Y == y + 1) {  //�������ڡ����룺����
                    user->password[j] = '\0';    //����������һ���ַ���Ϊ'\0'
                }
            }
        } else if (ch == '\b') {    //�ж��Ƿ�Ϊ�˸��
            if (pos.Y == y) {   //�������ڡ��ʺţ�����
                if (i > 0) {    //�ж��Ƿ�Ϊ��һ���ַ�
                    i--;
                    printf("\b \b");
                }
            } else if (pos.Y == y + 1) {  //�������ڡ����룺����
                if (j > 0) {    //�ж��Ƿ�Ϊ��һ���ַ�
                    j--;
                    printf("\b \b");
                }
            }
        } else {    //������ǻس������˸����������ַ�
            if (pos.Y == y) {    //�������ڡ��ʺţ�����
                if (ch >= '0' && ch <= '9') {
                    printf("%c", ch);
                    i++;
                } else {
                    setCursor(0, y + 3);
                    printf("�ʺ�ֻ��Ϊ���֣�\r");
                    Sleep(300);
                    printf("                          ");
                    setCursor(x + i, y);
                }
            } else if (pos.Y == y + 1) {  //�������ڡ����룺����
                if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch == '_' ||
                    ch == '@') {
                    printf("*");
                    j++;
                } else {
                    setCursor(0, y + 3);
                    printf("����ֻ��Ϊ���֡���ĸ���»��ߺ�@��\r");
                    Sleep(300);
                    printf("                                 ");
                    setCursor(x + j, y + 1);
                }
            }
        }
    } while (temp_y == y || temp_y == y + 1);    //�������ڡ��ʺţ��������룺�����������ѭ��
    setCursor(0, y + 3);    //������ƶ��������룺������һ��
}

//��¼ģ��
int loginMod(USER *temp_user) {
    USER local_user;
    int temp = 1;
    system("cls");
    printf("********************\n");
    printf("*       ��¼       *\n");
    printf("********************\n");
    inputAccountAndPassword(temp_user, 6, 3);    //�����ʺź�����
    //�ж��ļ��Ƿ���ڣ���������ڣ��򴴽��ļ�
    FILE *tfp = fopen("user.txt", "ab");
    fclose(tfp);
    FILE *fp;
    if ((fp = fopen("user.txt", "rb")) == NULL) {    //�ж��ļ��Ƿ�򿪳ɹ�
        printf("�ļ���ʧ�ܣ�\n");
        Sleep(1000);
        exit(0);
    }
    fread(&local_user, sizeof(USER), 1, fp);    //��ȡ�ļ��е��û���Ϣ
    while (1) {
        if (strcmp(temp_user->account, "") == 0) {    //�ж��ʺ��Ƿ�Ϊ��
            printf("�ʺŻ��������\n");
            temp = 0;
            break;
        }
        if (strcmp(temp_user->account, local_user.account) == 0 &&
            strcmp(temp_user->password, local_user.password) == 0) {    //�ж��ʺź������Ƿ���ȷ
            temp_user->role = local_user.role;    //���û��Ľ�ɫ��ֵ��temp_user
            printf("��¼�ɹ���\n");
            break;
        }
        if (!feof(fp)) {    //�ж��Ƿ񵽴��ļ�β
            fread(&local_user, sizeof(USER), 1, fp);    //��ȡ�ļ��е��û���Ϣ
        } else {
            printf("�ʺŻ��������\n");
            temp = 0;
            break;
        }
    }
    fclose(fp);    //�ر��ļ�
    Sleep(500);
    return temp;
}

//ע��ģ��
int registerMod(USER *temp_user) {
    int temp = 1;
    do {
        system("cls");
        printf("********************\n");
        printf("*       ע��       *\n");
        printf("********************\n");
        setCursor(0, 6);
        IN_REDWORD;
        printf("ѧ�������ʹ��ѧ��ע�ᣡ");
        IN_WHITE;
        setCursor(0, 3);
        inputAccountAndPassword(temp_user, 6, 3);    //�����ʺź�����
        //��֤����Ա��Կ
        char key[20], ch;
        IN_CYANWORD;
        printf("<�����ע��Ϊ��ʦ�����������Ա��Կ>\n<�����ע��Ϊѧ������ֱ�Ӱ��س���>\n");
        IN_WHITE;
        do {
            printf("���������Ա��Կ��");
            do {
                ch = getch();
                if (ch == '\b') {
                    if (strlen(key) > 0) {
                        key[strlen(key) - 1] = '\0';
                        printf("\b \b");
                    }
                } else if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch == '_' ||
                           ch == '@') {
                    printf("*");
                    key[strlen(key)] = ch;
                }
            } while (ch != '\r');
            key[strlen(key)] = '\0';
            if (strlen(key) == 0) {
                temp_user->role = 2;    //���û��Ľ�ɫ��Ϊѧ��
                printf("\n");   //����
                break;
            } else if (strcmp(key, ADMINKEY) == 0) {
                temp_user->role = 1;    //���û��Ľ�ɫ��Ϊ��ʦ
                printf("\n");   //����
                break;
            } else {
                for (int i = strlen(key); i >= 0; i--) {  //���key����
                    key[i] = '\0';
                }
                printf("\r                              \r");
                IN_REDWORD;
                printf("����Ա��Կ����");
                IN_WHITE;
                Sleep(500);
                printf("\r                \r");
            }
        } while (strcmp(key, ADMINKEY) != 0);

        //�ж��ļ��Ƿ���ڣ���������ڣ��򴴽��ļ�
        FILE *tfp = fopen("user.txt", "ab");
        fclose(tfp);

        FILE *rfp;
        if ((rfp = fopen("user.txt", "rb")) == NULL) {    //�ж��ļ��Ƿ�򿪳ɹ�
            printf("�ļ���ʧ�ܣ�\n");
            Sleep(1000);
            exit(0);
        }

        USER local_user;    //����һ���û��ṹ�����
        fread(&local_user, sizeof(USER), 1, rfp);    //��ȡ�ļ��е��û���Ϣ

        while (1) {
            if (strcmp(temp_user->account, local_user.account) == 0) {    //�ж��ʺ��Ƿ��Ѵ���
                printf("�ʺ��Ѵ��ڣ�\n");
                Sleep(500);
                temp = 0;
                break;
            }
            if (!feof(rfp)) {    //�ж��Ƿ񵽴��ļ�β
                fread(&local_user, sizeof(USER), 1, rfp);    //��ȡ�ļ��е��û���Ϣ
            } else {
                temp = 1;
                break;
            }
        }
        fclose(rfp);    //�ر��ļ�
    } while (temp == 0);    //����ʺ��Ѵ��ڣ������ѭ��

    FILE *wfp;
    if ((wfp = fopen("user.txt", "ab")) == NULL) {    //�ж��ļ��Ƿ�򿪳ɹ�
        printf("�ļ���ʧ�ܣ�\n");
        Sleep(1000);
        exit(0);
    }
    fwrite(temp_user, sizeof(USER), 1, wfp);    //���û���Ϣд���ļ�
    fclose(wfp);    //�ر��ļ�
    printf("ע��ɹ������Զ���¼��\n");
    Sleep(500);
    return temp;
}

//�������ܣ��˳���¼
void logoutMod(USER *user) {
    system("cls");
    printf("********************\n");
    printf("*       �˳�       *\n");
    printf("********************\n");
    free(user);    //�ͷ�userָ��
    login_status = 0;    //����¼״̬��Ϊδ��¼
    printf("�˳��ɹ���\n");
    Sleep(500);
}