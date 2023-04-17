// Created by VoidEmpty on 2023/4/4.

#ifndef V_SGMS_STUDENTDOUBLELIST_H
#define V_SGMS_STUDENTDOUBLELIST_H

#include "Struct.h"

extern int g_subjectNum;
extern int g_studentNum;

//�������ܣ�ѧ����Ϣ�����ʼ��
STU *doubleListCreate();

//�������ܣ������ڵ�
void Remove(STU *new);

//�������ܣ�ѧ����Ϣ�������
void doubleListInsert(STU *head, STU *new);

//�������ܣ�ѧ����Ϣ����ɾ��
void doubleListDelete(STU *head, STU *stu);

//�������ܣ�ѧ����Ϣ����ѧ�Ų���
STU *doubleListSearchID(STU *head, char *studentID);

//�������ܣ�ѧ����Ϣ������������
STU *doubleListSearchName(STU *head, char *studentName);

//�������ܣ�ѧ����Ϣ����д���ļ�
void doubleListWriteToFile(STU *head);

//�������ܣ�ѧ����Ϣ�����ȡ�ļ�
STU *doubleListReadFromFile();

//�������ܣ������ͷ�
void doubleListFree(STU *head);

//�������ܣ�ѧ����Ϣ�����ӡ
void doubleListPrint(STU *head);

/*�������ܣ�ѧ����Ϣ�����������
 * head��ѧ����Ϣ����ͷָ��
 * value���������ݣ�1���ܷ֣�2��ѧ�ţ�3������
 */
void doubleListInsertSort(STU *head, int value);

//�������ܣ����ѧ����Ϣ�����Ƿ�Ϊ��
int doubleListIsEmpty(STU *head);

#endif //V_SGMS_STUDENTDOUBLELIST_H
