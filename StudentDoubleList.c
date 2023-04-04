// Created by VoidEmpty on 2023/4/4.

#include "StudentDoubleList.h"

//函数功能：学生信息链表初始化
STU *doubleListCreate() {
    STU *head = (STU *) malloc(sizeof(STU));
    if (head == NULL) {
        printf("内存分配失败！");
        exit(0);
    }
    head->pre = head;
    head->next = NULL;
    return head;
}

//函数功能：学生信息链表添加
void doubleListAdd(STU *head, STU *stu) {
    STU *end = head->pre;
    end->next = stu;
    stu->pre = end;
    stu->next = NULL;
    head->pre = stu;
}

//函数功能：学生信息链表插入
void doubleListInsert(STU *head, STU *stu) {
    STU *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = stu;
    stu->pre = temp;
    stu->next = NULL;
}
