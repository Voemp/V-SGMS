// Created by VoidEmpty on 2023/4/3.
#ifndef V_SGMS_GRADEMANAGEMENT_H
#define V_SGMS_GRADEMANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Struct.h"
#include "StudentDoubleList.h"

extern int g_subjectNum;
extern int g_studentNum;

/*函数功能：录入学生成绩（教师版）
 * head：学生信息链表头指针
 * 返回值：无
 */
void readScoreInfinite(STU *head);

#endif //V_SGMS_GRADEMANAGEMENT_H
