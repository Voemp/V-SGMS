// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_LOGINSYSTEM_H
#define V_SGMS_LOGINSYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "FunctionLib.h"
#include "struct.h"

#define TEMPKEY -32
#define UPKEY 72
#define DOWNKEY 80

/*�������ܣ���¼ϵͳ����ͨ���������¼����У��س���ȷ��
 * �����������û�����ͷָ��,��ʼ���λ��x,��ʼ���λ��y
 * ��������ֵ����¼�ɹ�����1,��¼ʧ�ܷ���0
 */
int loginMod(USER *temp_user, int x, int y);

#endif //V_SGMS_LOGINSYSTEM_H
