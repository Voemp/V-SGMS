// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"

//�������ܣ���ѯ��ѯÿ�ſγ̵��ֺܷ�ƽ����
void queryTotalAndAverageScore(STU *stu, int stuNum, int courseNum) {
    int i, j;
    float totalScore = 0;
    float averageScore = 0;
    for (i = 0; i < courseNum; i++) {
        for (j = 0; j < stuNum; j++) {
            totalScore += stu[j].score[i];
        }
        averageScore = totalScore / stuNum;
        printf("��%d�ſγ̵��ܷ�Ϊ%.2f��ƽ����Ϊ%.2f\n", i + 1, totalScore, averageScore);
        totalScore = 0;
        averageScore = 0;
    }
}

}