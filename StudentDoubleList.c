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
    STU *end = head->pre;   //endָ������β�ڵ�
    end->next = stu;    //β�ڵ��nextָ���½ڵ�
    stu->pre = end;    //�½ڵ��preָ��β�ڵ�
    stu->next = NULL;   //�½ڵ��nextָ��NULL
    head->pre = stu;    //ͷ�ڵ��preָ���½ڵ�
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

//�������ܣ�ѧ����Ϣ����д���ļ�
void doubleListWriteToFile(STU *head) {
    FILE *fp = fopen("StudentInfo.txt", "wb");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    STU *temp = head->next;
    while (temp != NULL) {
        fwrite(temp, sizeof(STU), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}

//�������ܣ�ѧ����Ϣ�����ȡ�ļ�
STU *doubleListReadFromFile() {
    FILE *fp = fopen("StudentInfo.txt", "rb");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    STU *head = doubleListCreate();
    while (!feof(fp)) {
        fgetc(fp);    //�ȶ�һ�Σ��������ж��Ƿ��ļ�����������������ѭ��
        if (feof(fp))
            break;
        fseek(fp, -1, 1);       //���a���ֵ��ʹ�ã��ǵ�ǰ���ļ�ָ��
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

//�������ܣ������ͷ�
void doubleListFree(STU *head) {
    STU *temp = head->next;
    while (temp != NULL) {
        STU *temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    free(head);
}

//�������ܣ�ѧ����Ϣ�����ӡ
void doubleListPrint(STU *head) {
    STU *temp = head->next;
    while (temp != NULL) {
        printf("%-16s%-10s", temp->studentID, temp->studentName);
        for (int i = 0; i < g_subjectNum; ++i) {
            printf("\t%.1f", temp->score[i].subjectScore);
        }
        printf("\n");
        temp = temp->next;
    }
}

//�������ܣ�ѧ����Ϣ��������