// Created by VoidEmpty on 2023/4/4.

#ifndef V_SGMS_STUDENTDOUBLELIST_H
#define V_SGMS_STUDENTDOUBLELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Struct.h"

extern int g_subjectNum;
extern int g_studentNum;

//函数功能：学生信息链表初始化
STU *doubleListCreate();

//函数功能：弹出节点
void Remove(STU *new);

//函数功能：学生信息链表插入（尾插法）
void doubleListInsert(STU *head, STU *stu);

//函数功能：学生信息链表写入文件
void doubleListWriteToFile(STU *head);

//函数功能：学生信息链表读取文件
STU *doubleListReadFromFile();

//函数功能：链表释放
void doubleListFree(STU *head);

//函数功能：学生信息链表打印
void doubleListPrint(STU *head);

/*函数功能：学生信息链表插入排序
 * head：学生信息链表头指针
 * value：排序依据，1：总分，2：学号，3：姓名
 */
void doubleListInsertSort(STU *head, int value);

#endif //V_SGMS_STUDENTDOUBLELIST_H
