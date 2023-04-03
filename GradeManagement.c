// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"

//函数功能：查询查询每门课程的总分和平均分
void queryTotalAndAverageScore(STU *stu, int stuNum, int courseNum) {
    int i, j;
    float totalScore = 0;
    float averageScore = 0;
    for (i = 0; i < courseNum; i++) {
        for (j = 0; j < stuNum; j++) {
            totalScore += stu[j].score[i];
        }
        averageScore = totalScore / stuNum;
        printf("第%d门课程的总分为%.2f，平均分为%.2f\n", i + 1, totalScore, averageScore);
        totalScore = 0;
        averageScore = 0;
    }
}

}