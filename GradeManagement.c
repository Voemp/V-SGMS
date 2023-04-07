// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"


//函数功能：录入成绩
void readScore(STU *stu) {
    printf("请输入学号：");
    scanf("%s", stu->studentID);
    printf("请输入姓名：");
    scanf("%s", stu->studentName);
    for (int i = 0; i < g_subjectNum; ++i) {
        stu->score[i].subjectName = i + 1;
        printf("请输入第%d门的成绩：", stu->score[i].subjectName);
        scanf("%d", &stu->score[i].subjectScore);
    }
}

//函数功能：无限次录入成绩
void readScoreInfinite(STU *head) {
    int choice;
    do {
        system("cls");
        printf("************************\n");
        printf("*   学生成绩录入系统   *\n");
        printf("************************\n");
        STU *stu = (STU *) calloc(sizeof(STU), 1);
        if (stu == NULL) {
            printf("内存分配失败！");
            exit(0);
        }
        readScore(stu);
        doubleListAdd(head, stu);
        g_studentNum++;
        do {
            printf("是否继续录入？\n");
            IN_CYAN;
            printf("1.是\t2.否\n");
            IN_WHITE;
            choice = getch();
            if (choice != '1' && choice != '2') {
                printf("输入错误，请重新输入！\n");
                Sleep(300);
            }
        } while (choice != '1' && choice != '2');
    } while (choice == '1');
    printf("录入完成！即将返回菜单。。。\n");
    Sleep(500);
}


//函数功能：查询每门课程的总分和平均分
void queryTotalAndAverageScore(STU *stu) {

}

//函数功能：通用的功能调用函数
void commonFunction(int (*func)(STU *head)) {
    STU *head = doubleListReadFromFile();
    func(head);
    doubleListFree(head);
}