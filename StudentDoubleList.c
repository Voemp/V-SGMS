// Created by VoidEmpty on 2023/4/4.

#include "StudentDoubleList.h"

//�������ܣ�ѧ����Ϣ�����ʼ��
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

//�������ܣ�ѧ����Ϣ������ӣ�β�巨��
void doubleListAdd(STU *head, STU *stu) {
    STU *end = head->pre;
    end->next = stu;
    stu->pre = end;
    stu->next = NULL;
    head->pre = stu;
}

//�������ܣ�ѧ����Ϣ�������
void doubleListInsert(STU *head, STU *stu) {
    STU *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = stu;
    stu->pre = temp;
    stu->next = NULL;
}
