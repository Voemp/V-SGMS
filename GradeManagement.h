// Created by VoidEmpty on 2023/4/3.
#ifndef V_SGMS_GRADEMANAGEMENT_H
#define V_SGMS_GRADEMANAGEMENT_H

#include "Struct.h"

#define IN_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xb0)
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)

extern int g_subjectNum;
extern int g_studentNum;

//�������ܣ����ļ���ȡ���������Ϣ
void readBasicInfo();

/*�������ܣ�¼��ѧ���ɼ�����ʦ�棩
 * head��ѧ����Ϣ����ͷָ��
 * ����ֵ����
 */
void readScoreInfinite(STU *head);

//�������ܣ���ѯÿ�ſγ̵��ֺܷ�ƽ����
void queryTotalAndAverageScore(STU *head);

//�������ܣ�����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void queryRankAscending(STU *head);

#endif //V_SGMS_GRADEMANAGEMENT_H
