// Created by VoidEmpty on 2023/3/29.
#include "LoginSystem.h"

//�������ܣ���¼ģ��
int loginMod(USER *temp_user, int x, int y) {
    USER local_user;
    int temp = 1;
    int i = 0, j = 0;    //����ѭ������
    short temp_y;
    char ch;
    system("cls");
    printf("********************\n");
    printf("*       ��¼       *\n");
    printf("********************\n");
    printf("�ʺţ�\n");
    printf("���룺\n");
    setCursor(x, y);    //������ƶ������ʺţ�����
    do {
        if (getCursor().X > x + 20) {   //����ַ�������20�������ֹ����
            printf("\b \b");
            if (getCursor().Y == y) {
                i--;
                temp_user->account[i] = '\0';
                setCursor(0, y + 3);
                printf("�ʺų��Ȳ��ܳ���20���ַ���\r");
                Sleep(500);
                printf("                          ");
                setCursor(x + 20, y);
            } else if (getCursor().Y == y + 1) {
                j--;
                temp_user->password[j] = '\0';
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
            temp_user->account[i] = ch;    //������������ַ������ʺ���
        } else if (pos.Y == y + 1) {  //�������ڡ����룺����
            temp_user->password[j] = ch;    //������������ַ�����������
        } else {
            break;  //�����겻�ڡ��ʺţ��������룺���������˳�ѭ��
        }
        if (ch == '\r') {    //�ж��Ƿ�Ϊ�س���
            if (pos.Y == y) {   //�������ڡ��ʺţ�����
                temp_user->account[i] = '\0';    //���ʺŵ����һ���ַ���Ϊ'\0'
                setCursor(x + j, y + 1);    //������ƶ��������룺����
            } else if (pos.Y == y + 1) {  //�������ڡ����룺����
                temp_user->password[j] = '\0';    //����������һ���ַ���Ϊ'\0'
                break;  //�˳�ѭ��
            }
        } else if (ch == TEMPKEY) {    //�ж��Ƿ�Ϊ�����
            ch = getch();
            if (ch == UPKEY) {    //�ж��Ƿ�Ϊ���ϼ�
                if (pos.Y == y + 1) {  //�������ڡ����룺����
                    temp_user->password[j] = '\0';    //����������һ���ַ���Ϊ'\0'
                    setCursor(x + i, y);    //������ƶ������ʺţ�����
                } else if (pos.Y == y) {   //�������ڡ��ʺţ�����
                    temp_user->account[i] = '\0';    //���ʺŵ����һ���ַ���Ϊ'\0'
                }
            } else if (ch == DOWNKEY) {    //�ж��Ƿ�Ϊ���¼�
                if (pos.Y == y) {   //�������ڡ��ʺţ�����
                    temp_user->account[i] = '\0';    //���ʺŵ����һ���ַ���Ϊ'\0'
                    setCursor(x + j, y + 1);    //������ƶ��������룺����
                } else if (pos.Y == y + 1) {  //�������ڡ����룺����
                    temp_user->password[j] = '\0';    //����������һ���ַ���Ϊ'\0'
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
    FILE *fp;
    if ((fp = fopen("user.txt", "rb")) == NULL) {    //�ж��ļ��Ƿ�򿪳ɹ�
        printf("�ļ���ʧ�ܣ�\n");
        Sleep(1000);
        exit(0);
    }
    fread(&local_user, sizeof(USER), 1, fp);    //��ȡ�ļ��е��û���Ϣ
    while (1) {
        if (strcmp(temp_user->account, local_user.account) == 0 &&
            strcmp(temp_user->password, local_user.password) == 0) {    //�ж��ʺź������Ƿ���ȷ
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