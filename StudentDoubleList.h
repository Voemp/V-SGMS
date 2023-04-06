// Created by VoidEmpty on 2023/4/4.

#ifndef V_SGMS_STUDENTDOUBLELIST_H
#define V_SGMS_STUDENTDOUBLELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"

extern int g_subjectNum;
extern int g_studentNum;

//�������ܣ�˫�������ʼ��
STU *doubleListCreate();

//�������ܣ�˫��������ӣ�β�巨��
void doubleListAdd(STU *head, STU *stu);

//�������ܣ�˫������д���ļ�
void doubleListWriteToFile(STU *head);

//�������ܣ�˫�������ȡ�ļ�
STU *doubleListReadFromFile();

//�������ܣ�˫�������ӡ
void doubleListPrint(STU *head);

#endif //V_SGMS_STUDENTDOUBLELIST_H
