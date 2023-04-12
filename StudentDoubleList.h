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

//函数功能：学生信息链表添加（尾插法）
void doubleListAdd(STU *head, STU *stu);

//函数功能：学生信息链表写入文件
void doubleListWriteToFile(STU *head);

//函数功能：学生信息链表读取文件
STU *doubleListReadFromFile();

//函数功能：链表释放
void doubleListFree(STU *head);

//函数功能：学生信息链表打印
void doubleListPrint(STU *head);

#endif //V_SGMS_STUDENTDOUBLELIST_H
