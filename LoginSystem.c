// Created by VoidEmpty on 2023/3/29.
#include "LoginSystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "FunctionLib.h"

#define ADMINKEY 230417
#define TEMPKEY -32
#define UPKEY 72
#define DOWNKEY 80

//�������ܣ��ʺź���������
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
    Sleep(1000);
    return temp;
}

//ע��ģ��
int registerMod(USER *temp_user) {
    system("cls");
    printf("********************\n");
    printf("*       ע��       *\n");
    printf("********************\n");
    inputAccountAndPassword(temp_user, 6, 3);    //�����ʺź�����
    //��֤����Ա��Կ
    char key[20] = "";
    printf("<�����ע��Ϊ��ʦ�����������Ա��Կ>\n<�����ע��Ϊѧ����ֱ�Ӱ��س���>\n");
    printf("���������Ա��Կ��\n");
    scanf("%s", key);
    if (strcmp(key, "") == 0) {    //�жϹ���Ա��Կ�Ƿ���ȷ
        temp_user->role = 2;    //���û��Ľ�ɫ��Ϊ��ʦ
    } else {
        if (strcmp(key, "123456") == 0) {    //�жϹ���Ա��Կ�Ƿ���ȷ
            temp_user->role = 1;    //���û��Ľ�ɫ��Ϊѧ��
        } else {
            printf("����Ա��Կ����\n");
            Sleep(1000);
            return 0;
        }
    }
    FILE *fp;
    if ((fp = fopen("user.txt", "ab")) == NULL) {    //�ж��ļ��Ƿ�򿪳ɹ�
        printf("�ļ���ʧ�ܣ�\n");
        Sleep(1000);
        exit(0);
    }
    fwrite(temp_user, sizeof(USER), 1, fp);    //���û���Ϣд���ļ�
}