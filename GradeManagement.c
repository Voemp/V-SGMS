// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"

extern int g_subjectNum;
extern int g_studentNum;


//�������ܣ�¼��ɼ�
void readScore(STU *stu) {
    printf("������ѧ�ţ�");
    scanf("%s", stu->studentID);
    printf("������������");
    scanf("%s", stu->studentName);
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("�������%d�ŵĳɼ���", stu->score[i].subjectName);
        stu->score[i].subjectName = i + 1;
        scanf("%d", &stu->score[i].subjectScore);
    }
}

//�������ܣ����޴�¼��ɼ�
void readScoreInfinite(STU *head) {
    STU *stu = (STU *) malloc(sizeof(STU));
    if (stu == NULL) {
        printf("�ڴ����ʧ�ܣ�");
        exit(0);
    }
    readScore(stu);
    doubleListAdd(head, stu);
    g_studentNum++;
    int choice;
    do {
        printf("�Ƿ����¼�룿(1.�� 2.��)");
        scanf("%d", &choice);
        if (choice == 1) {
            stu = (STU *) malloc(sizeof(STU));
            if (stu == NULL) {
                printf("�ڴ����ʧ�ܣ�");
                exit(0);
            }
            readScore(stu);
            doubleListAdd(head, stu);
            g_studentNum++;
        } else if (choice == 2) {
            break;
        } else {
            printf("û�����ѡ�");
            Sleep(300);
        }
    } while (choice != 2);
}


//�������ܣ���ѯÿ�ſγ̵��ֺܷ�ƽ����
void queryTotalAndAverageScore(STU *stu) {

}