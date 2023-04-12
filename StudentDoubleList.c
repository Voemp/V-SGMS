// Created by VoidEmpty on 2023/4/4.

#include "StudentDoubleList.h"

//函数功能：学生信息链表初始化
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

//函数功能：弹出节点
void Remove(STU *new) {
    new->pre->next = new->next; //前驱的后继指向后继
    new->next->pre = new->pre;  //后继的前驱指向前驱
    new->next = new;    //后继指向自己
    new->pre = new;    //前驱指向自己
}

//函数功能：学生信息链表添加（尾插法）
void doubleListAdd(STU *head, STU *new) {
    new->pre = head->pre;   //新节点的前驱指向原链表的尾节点
    head->pre->next = new;  //原链表的尾节点的后继指向新节点
    new->next = NULL;    //新节点的后继指向NULL
    head->pre = new;    //头节点的前驱指向新节点
}

//函数功能：学生信息链表插入
void doubleListInsert(STU *head, STU *new) {
    new->pre = head->pre;   //新节点的前驱指向原链表的尾节点
    head->pre->next = new;  //原链表的尾节点的后继指向新节点
    new->next = head;    //新节点的后继指向头节点
    head->pre = new;    //头节点的前驱指向新节点
}

//函数功能：学生信息链表写入文件
void doubleListWriteToFile(STU *head) {
    FILE *fp = fopen("StudentInfo.txt", "wb");
    if (fp == NULL) {
        printf("文件打开失败！");
        exit(0);
    }
    STU *temp = head->next;
    while (temp != NULL) {
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
        doubleListAdd(head, stu);   //尾插法
    }
    fclose(fp);
    return head;
}

//函数功能：链表释放
void doubleListFree(STU *head) {
    STU *temp = head->next;
    while (temp != NULL) {
        STU *temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    free(head);
}

//函数功能：学生信息链表打印
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

/*函数功能：学生信息链表插入排序
 * head：学生信息链表头指针
 * value：排序依据，1：总分，2：学号，3：姓名
 */
void doubleListInsertSort(STU *head, int value) {
    //头结点是空的或者表是空的或者表只有一个节点时候不用排
    if (!head || head->next == NULL || head->next->next == NULL) {
        return;
    }
    STU *p, *q, *tail;
    //head->next->next开始遍历，tail及tail前面的是排好序的，p是本轮待插入值，等于head时结束
    for (tail = head->next, p = tail->next; p != head; p = tail->next) {
        //从head->next开始遍历，直到tail结束
        for (q = head; q != tail; q = q->next) {
            if (value == 1) {  //按总分排序
                //如果p的总分小于q的总分，就把p插入到q的前面
                if (p->totalScore < q->next->totalScore) {
                    Remove(p);  //从原位置删除p节点
                    doubleListInsert(q, p); //把p节点插入到q->next前面,即q的后面
                    break;
                }
            } else if (value == 2) {    //按学号排序
                //如果p的学号小于q的学号，就把p插入到q的前面
                if (strcmp(p->studentID, q->next->studentID) < 0) {
                    Remove(p);  //从原位置删除p节点
                    doubleListInsert(q, p); //把p节点插入到q->next前面,即q的后面
                    break;
                }
            } else if (value == 3) {   //按姓名排序
                //如果p的姓名小于q的姓名，就把p插入到q的前面
                if (strcmp(p->studentName, q->next->studentName) < 0) {
                    Remove(p);  //从原位置删除p节点
                    doubleListInsert(q, p); //把p节点插入到q->next前面,即q的后面
                    break;
                }
            }
            //if
        }
        tail = tail->next;  //下移tail
    }
}