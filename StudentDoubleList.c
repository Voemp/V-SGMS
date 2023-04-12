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

//�������ܣ������ڵ�
void Remove(STU *new) {
    new->pre->next = new->next; //ǰ���ĺ��ָ����
    new->next->pre = new->pre;  //��̵�ǰ��ָ��ǰ��
    new->next = new;    //���ָ���Լ�
    new->pre = new;    //ǰ��ָ���Լ�
}

//�������ܣ�ѧ����Ϣ������ӣ�β�巨��
void doubleListAdd(STU *head, STU *new) {
    new->pre = head->pre;   //�½ڵ��ǰ��ָ��ԭ�����β�ڵ�
    head->pre->next = new;  //ԭ�����β�ڵ�ĺ��ָ���½ڵ�
    new->next = NULL;    //�½ڵ�ĺ��ָ��NULL
    head->pre = new;    //ͷ�ڵ��ǰ��ָ���½ڵ�
}

//�������ܣ�ѧ����Ϣ�������
void doubleListInsert(STU *head, STU *new) {
    new->pre = head->pre;   //�½ڵ��ǰ��ָ��ԭ�����β�ڵ�
    head->pre->next = new;  //ԭ�����β�ڵ�ĺ��ָ���½ڵ�
    new->next = head;    //�½ڵ�ĺ��ָ��ͷ�ڵ�
    head->pre = new;    //ͷ�ڵ��ǰ��ָ���½ڵ�
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
        doubleListAdd(head, stu);   //β�巨
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

/*�������ܣ�ѧ����Ϣ�����������
 * head��ѧ����Ϣ����ͷָ��
 * value���������ݣ�1���ܷ֣�2��ѧ�ţ�3������
 */
void doubleListInsertSort(STU *head, int value) {
    //ͷ����ǿյĻ��߱��ǿյĻ��߱�ֻ��һ���ڵ�ʱ������
    if (!head || head->next == NULL || head->next->next == NULL) {
        return;
    }
    STU *p, *q, *tail;
    //head->next->next��ʼ������tail��tailǰ������ź���ģ�p�Ǳ��ִ�����ֵ������headʱ����
    for (tail = head->next, p = tail->next; p != head; p = tail->next) {
        //��head->next��ʼ������ֱ��tail����
        for (q = head; q != tail; q = q->next) {
            if (value == 1) {  //���ܷ�����
                //���p���ܷ�С��q���ܷ֣��Ͱ�p���뵽q��ǰ��
                if (p->totalScore < q->next->totalScore) {
                    Remove(p);  //��ԭλ��ɾ��p�ڵ�
                    doubleListInsert(q, p); //��p�ڵ���뵽q->nextǰ��,��q�ĺ���
                    break;
                }
            } else if (value == 2) {    //��ѧ������
                //���p��ѧ��С��q��ѧ�ţ��Ͱ�p���뵽q��ǰ��
                if (strcmp(p->studentID, q->next->studentID) < 0) {
                    Remove(p);  //��ԭλ��ɾ��p�ڵ�
                    doubleListInsert(q, p); //��p�ڵ���뵽q->nextǰ��,��q�ĺ���
                    break;
                }
            } else if (value == 3) {   //����������
                //���p������С��q���������Ͱ�p���뵽q��ǰ��
                if (strcmp(p->studentName, q->next->studentName) < 0) {
                    Remove(p);  //��ԭλ��ɾ��p�ڵ�
                    doubleListInsert(q, p); //��p�ڵ���뵽q->nextǰ��,��q�ĺ���
                    break;
                }
            }
            //if
        }
        tail = tail->next;  //����tail
    }
}