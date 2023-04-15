// Created by VoidEmpty on 2023/4/3.
#ifndef V_SGMS_GRADEMANAGEMENT_H
#define V_SGMS_GRADEMANAGEMENT_H

#include "Struct.h"

#define IN_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xb0)
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)

extern int g_subjectNum;
extern int g_studentNum;

//函数功能：从文件读取程序基本信息
void readBasicInfo();

/*函数功能：录入学生成绩（教师版）
 * head：学生信息链表头指针
 * 返回值：无
 */
void readScoreInfinite(STU *head);

//函数功能：查询每门课程的总分和平均分
void queryTotalAndAverageScore(STU *head);

//函数功能：按照每个学生的总分由高到低排出名次表
void queryRankAscending(STU *head);

//函数功能：按照每个学生的总分由低到高排出名次表
void queryRankDescending(STU *head);

//函数功能：按照学号由小到大排出成绩表
void queryRankID(STU *head);

/*函数功能：按要求查询学生排名及其各科考试成绩
 * 参数说明：head：双向循环链表的头结点
 *value：1表示按照学号查询，2表示按照姓名查询
 */
void checkStudent(STU *head, int value);

#endif //V_SGMS_GRADEMANAGEMENT_H
