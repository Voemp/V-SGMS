// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"


//�������ܣ�¼��ɼ�
void readScore(STU *stu) {
    printf("������ѧ�ţ�");
    scanf("%s", stu->studentID);
    printf("������������");
    scanf("%s", stu->studentName);
    for (int i = 0; i < g_subjectNum; ++i) {
        stu->score[i].subjectName = i + 1;
        printf("�������%d�ŵĳɼ���", stu->score[i].subjectName);
        scanf("%d", &stu->score[i].subjectScore);
    }
}

//�������ܣ����޴�¼��ɼ�
void readScoreInfinite(STU *head) {
    system("cls");
    printf("************************\n");
    printf("*   ѧ���ɼ�¼��ϵͳ   *\n");
    printf("************************\n");
    int choice;
    do {
        STU *stu = (STU *) calloc(sizeof(STU), 1);
        if (stu == NULL) {
            printf("�ڴ����ʧ�ܣ�");
            exit(0);
        }
        readScore(stu);
        doubleListAdd(head, stu);
        g_studentNum++;
        do {
            printf("�Ƿ����¼�룿");
            printf("1.��\t2.��\n");
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {
                printf("����������������룡\n");
                Sleep(300);
            }
        } while (choice != 1 && choice != 2);
    } while (choice == 1);
    printf("¼����ɣ��������ز˵�������\n");
    Sleep(500);
}


//�������ܣ���ѯÿ�ſγ̵��ֺܷ�ƽ����
void queryTotalAndAverageScore(STU *stu) {

}