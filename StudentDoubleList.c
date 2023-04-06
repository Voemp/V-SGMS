// Created by VoidEmpty on 2023/4/4.

#include "StudentDoubleList.h"

//函数功能：双向链表初始化
STU *doubleListCreate() {
    STU *head = (STU *) calloc(sizeof(STU), 1);
    if (head == NULL) {
        printf("内存分配失败！");
        exit(0);
    }
    head->pre = head;
    head->next = NULL;
    return head;
}

//函数功能：双向链表添加（尾插法）
void doubleListAdd(STU *head, STU *stu) {
    STU *end = head->pre;   //end指向链表尾节点
    end->next = stu;    //尾节点的next指向新节点
    stu->pre = end;    //新节点的pre指向尾节点
    stu->next = NULL;   //新节点的next指向NULL
    head->pre = stu;    //头节点的pre指向新节点
}

//函数功能：双向链表插入
void doubleListInsert(STU *head, STU *stu) {
    STU *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = stu;
    stu->pre = temp;
    stu->next = NULL;
}

//函数功能：双向链表写入文件
void doubleListWriteToFile(STU *head) {
    FILE *fp = fopen("StudentInfo.txt", "wb");
    if (fp == NULL) {
        printf("文件打开失败！");
        exit(0);
    }
    fwrite(head, sizeof(STU), 1, fp);
    STU *temp = head->next;
    while (temp != NULL) {
        fwrite(temp, sizeof(STU), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}

//函数功能：双向链表读取文件
STU *doubleListReadFromFile() {
    FILE *fp = fopen("StudentInfo.txt", "rb");
    if (fp == NULL) {
        printf("文件打开失败！");
        exit(0);
    }
    STU *head = doubleListCreate();
    STU *stu = (STU *) calloc(sizeof(STU), 1);
    if (stu == NULL) {
        printf("内存分配失败！");
        exit(0);
    }
    while (!feof(fp)) {
        STU *stu = (STU *) calloc(sizeof(STU), 1);
        if (stu == NULL) {
            printf("内存分配失败！");
            exit(0);
        }
        fread(stu, sizeof(STU), 1, fp);
        doubleListAdd(head, stu);
    }
    fclose(fp);
    return head;
}

//函数功能：双向链表打印
void doubleListPrint(STU *head) {
    STU *temp = head->next;
    while (temp != NULL) {
        printf("学号：%s\t姓名：%s\n", temp->studentID, temp->studentName);
        for (int i = 0; i < g_subjectNum; ++i) {
            printf("第%d门课程：%d\n", temp->score[i].subjectName, temp->score[i].subjectScore);
        }
        temp = temp->next;
    }
}