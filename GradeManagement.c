// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"

extern int g_subjectNum;
extern int g_studentNum;


//函数功能：录入成绩
void readScore(STU *stu) {
    printf("请输入学号：");
    scanf("%s", stu->studentID);
    printf("请输入姓名：");
    scanf("%s", stu->studentName);
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("请输入第%d门的成绩：", stu->score[i].subjectName);
        stu->score[i].subjectName = i + 1;
        scanf("%d", &stu->score[i].subjectScore);
    }
}

//函数功能：无限次录入成绩
void readScoreInfinite(STU *head) {
    STU *stu = (STU *) malloc(sizeof(STU));
    if (stu == NULL) {
        printf("内存分配失败！");
        exit(0);
    }
    readScore(stu);
    doubleListAdd(head, stu);
    g_studentNum++;
    int choice;
    do {
        printf("是否继续录入？(1.是 2.否)");
        scanf("%d", &choice);
        if (choice == 1) {
            stu = (STU *) malloc(sizeof(STU));
            if (stu == NULL) {
                printf("内存分配失败！");
                exit(0);
            }
            readScore(stu);
            doubleListAdd(head, stu);
            g_studentNum++;
        } else if (choice == 2) {
            break;
        } else {
            printf("没有这个选项！");
            Sleep(300);
        }
    } while (choice != 2);
}


//函数功能：查询每门课程的总分和平均分
void queryTotalAndAverageScore(STU *stu) {

}