// Created by VoidEmpty on 2023/4/4.

#include "StudentDoubleList.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//函数功能：学生信息链表初始化
STU *doubleListCreate() {
    STU *head = (STU *) calloc(sizeof(STU), 1);
    if (head == NULL) {
        printf("内存分配失败！");
        exit(0);
    }
    head->pre = head;
    head->next = head;
    return head;
}

//函数功能：弹出节点
void Remove(STU *new) {
    new->pre->next = new->next; //前驱的后继指向后继
    new->next->pre = new->pre;  //后继的前驱指向前驱
    new->next = new;    //后继指向自己
    new->pre = new;    //前驱指向自己
}

//函数功能：学生信息链表插入（尾插法）（前插法）
void doubleListInsert(STU *head, STU *new) {
    new->pre = head->pre;   //新节点的前驱指向原链表的尾节点
    head->pre->next = new;  //原链表的尾节点的后继指向新节点
    new->next = head;    //新节点的后继指向头节点
    head->pre = new;    //头节点的前驱指向新节点
}

//函数功能：学生信息链表按学号查找
STU *doubleListSearchID(STU *head, char *studentID) {
    STU *temp = head->next;
    while (temp != head) {
        if (strcmp(temp->studentID, studentID) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

//函数功能：学生信息链表按姓名查找
STU *doubleListSearchName(STU *head, char *studentName) {
    STU *temp = head->next;
    while (temp != head) {
        if (strcmp(temp->studentName, studentName) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

//函数功能：学生信息链表写入文件
void doubleListWriteToFile(STU *head) {
    FILE *fp = fopen("StudentInfo.txt", "wb");
    if (fp == NULL) {
        printf("文件打开失败！");
        exit(0);
    }
    STU *temp = head->next;
    while (temp != head) {
        fwrite(temp, sizeof(STU), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}

//函数功能：学生信息链表读取文件
STU *doubleListReadFromFile() {
    FILE *tfp = fopen("StudentInfo.txt", "ab");
    fclose(tfp);
    FILE *fp = fopen("StudentInfo.txt", "rb");
    if (fp == NULL) {
        printf("文件打开失败！");
        exit(0);
    }
    STU *head = doubleListCreate();
    while (!feof(fp)) {
        fgetc(fp);    //先读一次，下面再判断是否文件结束，结束则跳出循环
        if (feof(fp))
            break;
        fseek(fp, -1, 1);       //如果a这个值不使用，记得前移文件指针
        STU *stu = (STU *) calloc(sizeof(STU), 1);
        if (stu == NULL) {
            printf("内存分配失败！");
            Sleep(1000);
            exit(0);
        }
        fread(stu, sizeof(STU), 1, fp);
        doubleListInsert(head, stu);   //尾插法
    }
    fclose(fp);
    return head;
}

//函数功能：链表释放
void doubleListFree(STU *head) {
    STU *temp = head->next;
    while (temp != head) {
        STU *temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    free(head);
}

//函数功能：学生信息链表打印
void doubleListPrint(STU *head) {
    printf(" -----------------------------");
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("---------");
    }
    printf("------------------\n");
    printf("|       学号       |   姓名   |");
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("  第%d科 |", i + 1);
    }
    printf("  总分  | 平均分 |\n");
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

/*函数功能：学生信息链表插入排序
 * head：学生信息链表头指针
 * value：排序依据，1：总分，2：学号，3：姓名
 */
void doubleListInsertSort(STU *head, int value) {
    //头结点是空的或者表是空的或者表只有一个节点时候不用排
    if (!head || head->next == head || head->next->next == head) {
        return;
    }
    STU *p, *temp, *tail;
    //head->next->next开始遍历，tail及tail前面的是排好序的，p是本轮待插入值，等于head时结束
    for (tail = head->next, p = tail->next; p != head; p = tail->next) {
        //从head->next开始遍历，直到tail结束
        for (temp = head; temp != tail; temp = temp->next) {
            //因为doubleListInsert函数是前插法，所以要把p插入到temp->next前面！！！
            if (value == 1) {  //按总分排序
                //如果p的总分小于temp->next的总分，说明p应该插入到temp->next前面
                if (p->totalScore < temp->next->totalScore) {
                    Remove(p);  //从原位置删除p节点
                    doubleListInsert(temp->next, p);
                    break;
                }
            } else if (value == 2) {    //按学号排序
                //如果p的学号小于temp->next的学号，说明p应该插入到temp->next前面
                if (strcmp(p->studentID, temp->next->studentID) < 0) {
                    Remove(p);  //从原位置删除p节点
                    doubleListInsert(temp->next, p);
                    break;
                }
            } else if (value == 3) {   //按姓名排序
                //如果p的姓名小于temp->next的姓名，说明p应该插入到temp->next前面
                if (strcmp(p->studentName, temp->next->studentName) < 0) {
                    Remove(p);  //从原位置删除p节点
                    doubleListInsert(temp->next, p);
                    break;
                }
            }
        }
        if (tail == temp) {   //在tail前面没有插入，就下移
            tail = tail->next;
        }
    }
}

//函数功能：检测学生信息链表是否为空
int doubleListIsEmpty(STU *head) {
    if (head->next == head) {
        printf("学生信息为空！\n");
        return 1;
    }
    return 0;
}