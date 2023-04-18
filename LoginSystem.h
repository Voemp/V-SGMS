// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_LOGINSYSTEM_H
#define V_SGMS_LOGINSYSTEM_H

#include "struct.h"

extern USER *g_user;    //ȫ�ֱ��������ڴ洢��ǰ��¼�û�����Ϣ
extern int login_status;   //ȫ�ֱ��������ڴ洢��ǰ��¼״̬��0Ϊδ��¼��1Ϊ��¼

//��¼����
void loginSystem();

/*�������ܣ���¼ϵͳ����ͨ���������¼����У��س���ȷ��
 * �����������û�����ͷָ��,��ʼ���λ��x,��ʼ���λ��y
 * ��������ֵ����¼�ɹ�����1,��¼ʧ�ܷ���0
 */
int loginMod(USER *temp_use);

/*�������ܣ�ע��ϵͳ����ͨ���������¼����У��س���ȷ��
 * �����������û�����ͷָ��,��ʼ���λ��x,��ʼ���λ��y
 * ��������ֵ��ע��ɹ�����1,ע��ʧ�ܷ���0
 */
int registerMod(USER *temp_user);

//�������ܣ��˳���¼
void logoutMod(USER *user);

#endif //V_SGMS_LOGINSYSTEM_H
