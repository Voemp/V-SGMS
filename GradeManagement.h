// Created by VoidEmpty on 2023/4/3.
#ifndef V_SGMS_GRADEMANAGEMENT_H
#define V_SGMS_GRADEMANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Struct.h"
#include "StudentDoubleList.h"

#define IN_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xb0)
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)

extern int g_subjectNum;
extern int g_studentNum;

/*�������ܣ�¼��ѧ���ɼ�����ʦ�棩
 * head��ѧ����Ϣ����ͷָ��
 * ����ֵ����
 */
void readScoreInfinite(STU *head);

#endif //V_SGMS_GRADEMANAGEMENT_H
