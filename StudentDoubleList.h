// Created by VoidEmpty on 2023/4/4.

#ifndef V_SGMS_STUDENTDOUBLELIST_H
#define V_SGMS_STUDENTDOUBLELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Struct.h"

extern int g_subjectNum;
extern int g_studentNum;

//�������ܣ�ѧ����Ϣ�����ʼ��
STU *doubleListCreate();

//�������ܣ�ѧ����Ϣ������ӣ�β�巨��
void doubleListAdd(STU *head, STU *stu);

//�������ܣ�ѧ����Ϣ����д���ļ�
void doubleListWriteToFile(STU *head);

//�������ܣ�ѧ����Ϣ�����ȡ�ļ�
STU *doubleListReadFromFile();

//�������ܣ������ͷ�
void doubleListFree(STU *head);

//�������ܣ�ѧ����Ϣ�����ӡ
void doubleListPrint(STU *head);

#endif //V_SGMS_STUDENTDOUBLELIST_H
