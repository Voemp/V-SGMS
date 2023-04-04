// Created by VoidEmpty on 2023/4/4.

#ifndef V_SGMS_STUDENTDOUBLELIST_H
#define V_SGMS_STUDENTDOUBLELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"

//函数功能：学生信息链表初始化
STU *doubleListCreate();

//函数功能：学生信息链表添加
void doubleListAdd(STU *head, STU *stu);

#endif //V_SGMS_STUDENTDOUBLELIST_H
