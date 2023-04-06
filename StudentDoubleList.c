// Created by VoidEmpty on 2023/4/4.

#include "StudentDoubleList.h"

//�������ܣ�˫�������ʼ��
STU *doubleListCreate() {
    STU *head = (STU *) calloc(sizeof(STU), 1);
    if (head == NULL) {
        printf("�ڴ����ʧ�ܣ�");
        exit(0);
    }
    head->pre = head;
    head->next = NULL;
    return head;
}

//�������ܣ�˫��������ӣ�β�巨��
void doubleListAdd(STU *head, STU *stu) {
    STU *end = head->pre;   //endָ������β�ڵ�
    end->next = stu;    //β�ڵ��nextָ���½ڵ�
    stu->pre = end;    //�½ڵ��preָ��β�ڵ�
    stu->next = NULL;   //�½ڵ��nextָ��NULL
    head->pre = stu;    //ͷ�ڵ��preָ���½ڵ�
}

//�������ܣ�˫���������
void doubleListInsert(STU *head, STU *stu) {
    STU *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = stu;
    stu->pre = temp;
    stu->next = NULL;
}

//�������ܣ�˫������д���ļ�
void doubleListWriteToFile(STU *head) {
    FILE *fp = fopen("StudentInfo.txt", "wb");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
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

//�������ܣ�˫�������ȡ�ļ�
STU *doubleListReadFromFile() {
    FILE *fp = fopen("StudentInfo.txt", "rb");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    STU *head = doubleListCreate();
    STU *stu = (STU *) calloc(sizeof(STU), 1);
    if (stu == NULL) {
        printf("�ڴ����ʧ�ܣ�");
        exit(0);
    }
    while (!feof(fp)) {
        STU *stu = (STU *) calloc(sizeof(STU), 1);
        if (stu == NULL) {
            printf("�ڴ����ʧ�ܣ�");
            exit(0);
        }
        fread(stu, sizeof(STU), 1, fp);
        doubleListAdd(head, stu);
    }
    fclose(fp);
    return head;
}

//�������ܣ�˫�������ӡ
void doubleListPrint(STU *head) {
    STU *temp = head->next;
    while (temp != NULL) {
        printf("ѧ�ţ�%s\t������%s\n", temp->studentID, temp->studentName);
        for (int i = 0; i < g_subjectNum; ++i) {
            printf("��%d�ſγ̣�%d\n", temp->score[i].subjectName, temp->score[i].subjectScore);
        }
        temp = temp->next;
    }
}