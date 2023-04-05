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
    system("cls");
    printf("************************\n");
    printf("*   学生成绩录入系统   *\n");
    printf("************************\n");
    int choice;
    do {
        if (g_studentNum == 0) {    //如果是第一次录入成绩
            readScore(head);
            g_studentNum++;
        } else {    //如果不是第一次录入成绩
            STU *stu = (STU *) malloc(sizeof(STU));
            if (stu == NULL) {
                printf("内存分配失败！");
                exit(0);
            }
            readScore(stu);
            doubleListAdd(head, stu);
            g_studentNum++;
        }
        do {
            printf("是否继续录入？");
            printf("1.是\t2.否\n");
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {
                printf("输入错误，请重新输入！\n");
                Sleep(300);
            }
        } while (choice != 1 && choice != 2);
    } while (choice == 1);
    printf("录入完成！即将返回菜单。。。\n");
    Sleep(500);
}


//函数功能：查询每门课程的总分和平均分
void queryTotalAndAverageScore(STU *stu) {

}