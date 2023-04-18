// Created by VoidEmpty on 2023/4/3.
#ifndef V_SGMS_GRADEMANAGEMENT_H
#define V_SGMS_GRADEMANAGEMENT_H

#include "Struct.h"

#define IN_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xb0)
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)

extern int g_subjectNum;
extern int g_studentNum;
extern USER *g_user;

//�������ܣ����ļ���ȡ���������Ϣ
void readBasicInfo();

//�������ܣ�¼��ѧ���ɼ�����ʦ�棩
void readScoreInfinite(STU *head);

//�������ܣ��޸ĳɼ�����ʦ�棩
void modifyScore(STU *head);

//�������ܣ�ɾ��ѧ����Ϣ����ʦ�棩
void deleteStudent(STU *head);

//�������ܣ���ѯÿ�ſγ̵��ֺܷ�ƽ����
void queryTotalAndAverageScore(STU *head);

//�������ܣ�����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void queryRankAscending(STU *head);

//�������ܣ�����ÿ��ѧ�����ܷ��ɵ͵����ų����α�
void queryRankDescending(STU *head);

//�������ܣ�����ѧ����С�����ų��ɼ���
void queryRankID(STU *head);

/*�������ܣ���Ҫ���ѯѧ������������ƿ��Գɼ�
 * ����˵����head��˫��ѭ�������ͷ���
 *value��1��ʾ����ѧ�Ų�ѯ��2��ʾ����������ѯ
 */
void checkStudent(STU *head, int value);

/*�������ܣ������㣨90-100�������ã�80-89�����еȣ�70-79��������60-69����
 * ������0-59�� 5 �����ͳ��ÿ�����������Լ���ռ�İٷֱ�
 * ����˵����head��˫��ѭ�������ͷ���
 */
void statisticalScores(STU *head);

//�������ܣ����ȫ����Ϣ
void printAll(STU *head);

//�������ܣ���ѯ�Լ��ĳɼ���ѧ����
void checkMyScore(STU *head);

//�������ܣ����ÿ�Ŀ����
void setSubjectNum();

#endif //V_SGMS_GRADEMANAGEMENT_H
