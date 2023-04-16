// Created by VoidEmpty on 2023/4/4.

#include "StudentDoubleList.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//�������ܣ�ѧ����Ϣ�����ʼ��
STU *doubleListCreate() {
    STU *head = (STU *) calloc(sizeof(STU), 1);
    if (head == NULL) {
        printf("�ڴ����ʧ�ܣ�");
        exit(0);
    }
    head->pre = head;
    head->next = head;
    return head;
}

//�������ܣ������ڵ�
void Remove(STU *new) {
    new->pre->next = new->next; //ǰ���ĺ��ָ����
    new->next->pre = new->pre;  //��̵�ǰ��ָ��ǰ��
    new->next = new;    //���ָ���Լ�
    new->pre = new;    //ǰ��ָ���Լ�
}

//�������ܣ�ѧ����Ϣ������루β�巨����ǰ�巨��
void doubleListInsert(STU *head, STU *new) {
    new->pre = head->pre;   //�½ڵ��ǰ��ָ��ԭ�����β�ڵ�
    head->pre->next = new;  //ԭ�����β�ڵ�ĺ��ָ���½ڵ�
    new->next = head;    //�½ڵ�ĺ��ָ��ͷ�ڵ�
    head->pre = new;    //ͷ�ڵ��ǰ��ָ���½ڵ�
}

//�������ܣ�ѧ����Ϣ����ѧ�Ų���
STU *doubleListSearchID(STU *head, char *studentID) {
    STU *temp = head->next;
    while (temp != head) {
        if (strcmp(temp->studentID, studentID) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

//�������ܣ�ѧ����Ϣ������������
STU *doubleListSearchName(STU *head, char *studentName) {
    STU *temp = head->next;
    while (temp != head) {
        if (strcmp(temp->studentName, studentName) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

//�������ܣ�ѧ����Ϣ����д���ļ�
void doubleListWriteToFile(STU *head) {
    FILE *fp = fopen("StudentInfo.txt", "wb");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    STU *temp = head->next;
    while (temp != head) {
        fwrite(temp, sizeof(STU), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}

//�������ܣ�ѧ����Ϣ�����ȡ�ļ�
STU *doubleListReadFromFile() {
    FILE *tfp = fopen("StudentInfo.txt", "ab");
    fclose(tfp);
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
            Sleep(1000);
            exit(0);
        }
        fread(stu, sizeof(STU), 1, fp);
        doubleListInsert(head, stu);   //β�巨
    }
    fclose(fp);
    return head;
}

//�������ܣ������ͷ�
void doubleListFree(STU *head) {
    STU *temp = head->next;
    while (temp != head) {
        STU *temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    free(head);
}

//�������ܣ�ѧ����Ϣ�����ӡ
void doubleListPrint(STU *head) {
    printf(" -----------------------------");
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("---------");
    }
    printf("------------------\n");
    printf("|       ѧ��       |   ����   |");
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("  ��%d�� |", i + 1);
    }
    printf("  �ܷ�  | ƽ���� |\n");
    printf(" -----------------------------");
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("---------");
    }
    printf("------------------\n");
    STU *temp = head->next;
    while (temp != head) {
        printf("| %-16s | %-8s |", temp->studentID, temp->studentName);
        for (int i = 0; i < g_subjectNum; ++i) {
            printf(" %6.1f |", temp->score[i].subjectScore);
        }
        printf(" %6.1f | %6.1f |\n", temp->totalScore, temp->averageScore);
        printf(" -----------------------------");
        for (int i = 0; i < g_subjectNum; ++i) {
            printf("---------");
        }
        printf("------------------\n");
        temp = temp->next;
    }
}

/*�������ܣ�ѧ����Ϣ�����������
 * head��ѧ����Ϣ����ͷָ��
 * value���������ݣ�1���ܷ֣�2��ѧ�ţ�3������
 */
void doubleListInsertSort(STU *head, int value) {
    //ͷ����ǿյĻ��߱��ǿյĻ��߱�ֻ��һ���ڵ�ʱ������
    if (!head || head->next == head || head->next->next == head) {
        return;
    }
    STU *p, *temp, *tail;
    //head->next->next��ʼ������tail��tailǰ������ź���ģ�p�Ǳ��ִ�����ֵ������headʱ����
    for (tail = head->next, p = tail->next; p != head; p = tail->next) {
        //��head->next��ʼ������ֱ��tail����
        for (temp = head; temp != tail; temp = temp->next) {
            //��ΪdoubleListInsert������ǰ�巨������Ҫ��p���뵽temp->nextǰ�棡����
            if (value == 1) {  //���ܷ�����
                //���p���ܷ�С��temp->next���ܷ֣�˵��pӦ�ò��뵽temp->nextǰ��
                if (p->totalScore < temp->next->totalScore) {
                    Remove(p);  //��ԭλ��ɾ��p�ڵ�
                    doubleListInsert(temp->next, p);
                    break;
                }
            } else if (value == 2) {    //��ѧ������
                //���p��ѧ��С��temp->next��ѧ�ţ�˵��pӦ�ò��뵽temp->nextǰ��
                if (strcmp(p->studentID, temp->next->studentID) < 0) {
                    Remove(p);  //��ԭλ��ɾ��p�ڵ�
                    doubleListInsert(temp->next, p);
                    break;
                }
            } else if (value == 3) {   //����������
                //���p������С��temp->next��������˵��pӦ�ò��뵽temp->nextǰ��
                if (strcmp(p->studentName, temp->next->studentName) < 0) {
                    Remove(p);  //��ԭλ��ɾ��p�ڵ�
                    doubleListInsert(temp->next, p);
                    break;
                }
            }
        }
        if (tail == temp) {   //��tailǰ��û�в��룬������
            tail = tail->next;
        }
    }
}

//�������ܣ����ѧ����Ϣ�����Ƿ�Ϊ��
int doubleListIsEmpty(STU *head) {
    if (head->next == head) {
        printf("ѧ����ϢΪ�գ�\n");
        return 1;
    }
    return 0;
}