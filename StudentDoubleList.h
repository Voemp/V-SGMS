// Created by VoidEmpty on 2023/4/4.

#ifndef V_SGMS_STUDENTDOUBLELIST_H
#define V_SGMS_STUDENTDOUBLELIST_H

#include "Struct.h"

extern int g_subjectNum;
extern int g_studentNum;

//函数功能：学生信息链表初始化
STU *doubleListCreate();

//函数功能：弹出节点
void Remove(STU *new);

//函数功能：学生信息链表插入
void doubleListInsert(STU *head, STU *new);

//函数功能：学生信息链表删除
void doubleListDelete(STU *head, STU *stu);

//函数功能：学生信息链表按学号查找
STU *doubleListSearchID(STU *head, char *studentID);

//函数功能：学生信息链表按姓名查找
STU *doubleListSearchName(STU *head, char *studentName);

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

//函数功能：检测学生信息链表是否为空
int doubleListIsEmpty(STU *head);

#endif //V_SGMS_STUDENTDOUBLELIST_H
