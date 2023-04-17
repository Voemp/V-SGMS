// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "StudentDoubleList.h"

//�������ܣ����ļ���ȡ���������Ϣ
void readBasicInfo() {
    FILE *tfp = fopen("BasicInfo.txt", "a");
    fclose(tfp);
    FILE *fp = fopen("BasicInfo.txt", "r");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    fscanf(fp, "%d", &g_studentNum);
    fclose(fp);
}

//�����ֿ�ʼ

//�������ܣ�¼��ɼ�
void readScore(STU *stu) {
    stu->totalScore = 0;    //��ʼ���ܷ�
    printf("������ѧ�ţ�");
    scanf("%s", stu->studentID);
    printf("������������");
    scanf("%s", stu->studentName);
    for (int i = 0; i < g_subjectNum; ++i) {
        stu->score[i].subjectName = i + 1;
        printf("�������%d�ŵĳɼ���", stu->score[i].subjectName);
        scanf("%f", &stu->score[i].subjectScore);
        stu->totalScore += stu->score[i].subjectScore;  //�����ܷ�
    }
    stu->averageScore = stu->totalScore / g_subjectNum;   //����ƽ����
}

//�������ܣ����޴�¼��ɼ�����ʦ�棩
void readScoreInfinite(STU *head) {
    int choice;
    do {
        system("cls");
        printf("******************\n");
        printf("*ѧ���ɼ�¼��ϵͳ*\n");
        printf("******************\n");
        printf(">>>\n");
        STU *stu = (STU *) calloc(sizeof(STU), 1);
        if (stu == NULL) {
            printf("�ڴ����ʧ�ܣ�");
            exit(0);
        }
        readScore(stu);
        doubleListInsert(head, stu);   //β�巨
        g_studentNum++;
        printf("¼��ɹ�����ǰѧ��������%d\n", g_studentNum);
        printf("�Ƿ����¼�룿\n");
        IN_CYAN;
        printf("1.��\t2.��\n");
        IN_WHITE;
        do {
            choice = getch();
            if (choice != '1' && choice != '2') {
                printf("����������������룡\r");
                Sleep(500);
                printf("                      \r");   //������������ʾ
            }
        } while (choice != '1' && choice != '2');   //�����������������
    } while (choice == '1');    //����1�����¼��
    printf("¼����ɣ��������ز˵�������\n");
    FILE *fp = fopen("BasicInfo.txt", "w");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    fprintf(fp, "%d", g_studentNum);
    fclose(fp);

    Sleep(500);
}

//�������ܣ��޸ĳɼ�����ʦ�棩
void modifyScore(STU *head) {
    system("cls");
    printf("******************\n");
    printf("*ѧ���ɼ��޸�ϵͳ*\n");
    printf("******************\n");
    printf(">>>\n");
    char studentID[20];
    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
    scanf("%s", studentID);
    STU *temp = head->next;  //ͷ��㲻�������
    while (temp != head) {
        if (strcmp(temp->studentID, studentID) == 0) {
            printf("ѧ�ţ�%s\t������%s\n", temp->studentID, temp->studentName);
            printf("������Ҫ�޸ĵĿ�Ŀ��ţ�");
            int subjectNum;
            scanf("%d", &subjectNum);
            printf("�������޸ĺ�ĳɼ���");
            float subjectScore;
            scanf("%f", &subjectScore);
            temp->totalScore -= temp->score[subjectNum - 1].subjectScore;  //��ȥԭ�ɼ�
            temp->score[subjectNum - 1].subjectScore = subjectScore;  //�޸ĳɼ�
            temp->totalScore += temp->score[subjectNum - 1].subjectScore;  //�����³ɼ�
            temp->averageScore = temp->totalScore / g_subjectNum;   //����ƽ����
            printf("�޸ĳɹ���\n");
            return;
        }
        temp = temp->next;
    }
    printf("δ�ҵ���ѧ����\n");
}

//�������ܣ�ɾ��ѧ����Ϣ����ʦ�棩
void deleteStudent(STU *head) {
    int choice;  //�����жϱ����Ƿ�ɾ��
    char studentID[20];
    do {
        system("cls");
        printf("******************\n");
        printf("*ѧ����Ϣɾ��ϵͳ*\n");
        printf("******************\n");
        printf(">>>\n");
        printf("������Ҫɾ����ѧ��ѧ�ţ�");
        scanf("%s", studentID);
        STU *temp = head->next;  //ͷ��㲻�������
        while (temp != head) {
            if (strcmp(temp->studentID, studentID) == 0) {
                break;
            }
            temp = temp->next;
        }
        if (temp == head) {
            printf("δ�ҵ���ѧ����\n");
            choice = '2';
            Sleep(500);
        } else {
            printf("ѧ�ţ�%s\t������%s\n", temp->studentID, temp->studentName);
            //ȷ���Ƿ�ɾ��
            printf("�Ƿ�ɾ����\n");
            IN_CYAN;
            printf("1.��\t2.��\n");
            IN_WHITE;
            do {
                choice = getch();
                if (choice == '1') {
                    doubleListDelete(head, temp);
                    g_studentNum--;  //ѧ��������һ
                    printf("ɾ���ɹ�����ǰѧ��������%d\n", g_studentNum);
                    Sleep(500);
                    return;
                } else if (choice == '2') {
                    printf("��ȡ��ɾ����\n");
                    Sleep(500);
                } else {
                    printf("����������������룡\r");
                    Sleep(500);
                    printf("                      \r");   //������������ʾ
                }
            } while (choice != '1' && choice != '2');   //�����������������
        }
    } while (choice == '2');    //����2����������
}

//�����ֽ���


//��ѯ���ֿ�ʼ

//�������ܣ���ѯÿ�ſγ̵��ֺܷ�ƽ����
void printTotalAndAverageScore(STU *head) {
    printf(" -----------------------------\n");
    printf("|  �γ����� |  �ܷ�  | ƽ���� |\n");
    printf(" -----------------------------\n");
    float *total_score = calloc(sizeof(float), g_subjectNum);
    if (total_score == NULL) {
        printf("�ڴ����ʧ�ܣ�");
        exit(0);
    }
    STU *temp = head->next;  //ͷ��㲻�������
    //�����ܷ�
    while (temp != head) {
        for (int i = 0; i < g_subjectNum; ++i) {
            total_score[i] += temp->score[i].subjectScore;
        }
        temp = temp->next;
    }
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("| ��%d�ſγ� | %6.1f | %6.1f |\n", i + 1, total_score[i], total_score[i] / g_studentNum);
        printf(" -----------------------------\n");
    }
    free(total_score);
}

//�������ܣ���ѯÿ�ſγ̵��ֺܷ�ƽ����
void queryTotalAndAverageScore(STU *head) {
    system("cls");
    if (doubleListIsEmpty(head) == 1)   //�ж������Ƿ�Ϊ��
        return;
    printf("************************\n");
    printf("*ÿ�ſγ̵��ֺܷ�ƽ����*\n");
    printf("************************\n");
    printf(">>>\n");
    printTotalAndAverageScore(head);
}

//�������ܣ�����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void queryRankAscending(STU *head) {
    system("cls");
    if (doubleListIsEmpty(head) == 1)   //�ж������Ƿ�Ϊ��
        return;
    printf("********************************\n");
    printf("*��ѧ�����ܷ��ɸߵ����ų����α�*\n");
    printf("********************************\n");
    printf(">>>\n");
    printf(" ---------------------------------------------\n");
    printf("|       ѧ��       |   ����   |  �ܷ�  | ���� |\n");
    printf(" ---------------------------------------------\n");
    doubleListInsertSort(head, 1);  //�����ܷ��ɸߵ�������
    STU *temp = head->pre;  //ͷ��㲻�������
    int rank = 1;
    while (temp != head) {
        printf("| %-16s | %-8s | %6.1f | %4d |\n", temp->studentID, temp->studentName, temp->totalScore, rank);
        printf(" ---------------------------------------------\n");
        temp = temp->pre;
        rank++;
    }
}

//�������ܣ�����ÿ��ѧ�����ܷ��ɵ͵����ų����α�
void queryRankDescending(STU *head) {
    system("cls");
    if (doubleListIsEmpty(head) == 1)   //�ж������Ƿ�Ϊ��
        return;
    printf("********************************\n");
    printf("*��ѧ�����ܷ��ɵ͵����ų����α�*\n");
    printf("********************************\n");
    printf(">>>\n");
    printf(" ---------------------------------------------\n");
    printf("|       ѧ��       |   ����   |  �ܷ�  | ���� |\n");
    printf(" ---------------------------------------------\n");
    doubleListInsertSort(head, 1);  //�����ܷ��ɸߵ�������
    STU *temp = head->next;  //ͷ��㲻�������
    int rank = 1;
    while (temp != head) {
        printf("| %-16s | %-8s | %6.1f | %4d |\n", temp->studentID, temp->studentName, temp->totalScore, rank);
        printf(" ---------------------------------------------\n");
        temp = temp->next;
        rank++;
    }
}

//�������ܣ�����ѧ����С�����ų��ɼ���
void queryRankID(STU *head) {
    system("cls");
    if (doubleListIsEmpty(head) == 1)   //�ж������Ƿ�Ϊ��
        return;
    printf("****************************\n");
    printf("*����ѧ����С�����ų��ɼ���*\n");
    printf("****************************\n");
    printf(">>>\n");
    doubleListInsertSort(head, 2);   //����ѧ����С��������
    doubleListPrint(head);
}

/*�������ܣ���Ҫ���ѯѧ������������ƿ��Գɼ�
 * ����˵����head��˫��ѭ�������ͷ���
 *value��1��ʾ����ѧ�Ų�ѯ��2��ʾ����������ѯ
 */
void checkStudent(STU *head, int value) {
    int choice = 0;
    do {
        system("cls");
        if (doubleListIsEmpty(head) == 1)   //�ж������Ƿ�Ϊ��
            return;
        STU *outcome = NULL;
        if (value == 1) {
            printf("************************************\n");
            printf("*��ѧ�Ų�ѯѧ������������ƿ��Գɼ�*\n");
            printf("************************************\n");
            printf(">>>\n");
            printf("��������Ҫ���ҵ�ѧ�ţ�");
            char studentID[20];
            scanf("%s", studentID);
            printf(">>>\n");
            outcome = doubleListSearchID(head, studentID);
        } else if (value == 2) {
            printf("************************************\n");
            printf("*��������ѯѧ������������ƿ��Գɼ�*\n");
            printf("************************************\n");
            printf(">>>\n");
            printf("��������Ҫ���ҵ�������");
            char studentName[20];
            scanf("%s", studentName);
            printf(">>>\n");
            outcome = doubleListSearchName(head, studentName);
        }
        if (outcome == NULL) {
            choice = 0;
            printf("δ�ҵ���ѧ����");
            Sleep(500);
        } else {
            printf(" -----------------------------");
            for (int i = 0; i < g_subjectNum; ++i) {
                printf("---------");
            }
            printf("-------------------------\n");
            printf("|       ѧ��       |   ����   |");
            for (int i = 0; i < g_subjectNum; ++i) {
                printf("  ��%d�� |", i + 1);
            }
            printf("  �ܷ�  | ƽ���� | ���� |\n");
            printf(" -----------------------------");
            for (int i = 0; i < g_subjectNum; ++i) {
                printf("---------");
            }
            printf("-------------------------\n");

            printf("| %-16s | %-8s |", outcome->studentID, outcome->studentName);
            for (int i = 0; i < g_subjectNum; ++i) {
                printf(" %6.1f |", outcome->score[i].subjectScore);
            }
            printf(" %6.1f | %6.1f |", outcome->totalScore, outcome->averageScore);
            //�����ܷ��ɸߵ�������
            doubleListInsertSort(head, 1);
            STU *temp = head->pre;  //ͷ��㲻�������
            int rank = 1;
            while (temp != head) {  //��������
                if (strcmp(temp->studentID, outcome->studentID) == 0) {
                    printf(" %4d |\n", rank);
                    break;
                }
                temp = temp->pre;
                rank++;
            }

            printf(" -----------------------------");
            for (int i = 0; i < g_subjectNum; ++i) {
                printf("---------");
            }
            printf("-------------------------\n");
            choice = 1;
        }
    } while (choice == 0);
}

/*�������ܣ������㣨90-100�������ã�80-89�����еȣ�70-79��������60-69����
 * ������0-59�� 5 �����ͳ��ÿ�����������Լ���ռ�İٷֱ�
 * ����˵����head��˫��ѭ�������ͷ���
 */
void statisticalScores(STU *head) {
    system("cls");
    if (doubleListIsEmpty(head) == 1)   //�ж������Ƿ�Ϊ��
        return;
    printf("****************************\n");
    printf("*ͳ�Ʋ�ͬ�����ε������ٷֱ�*\n");
    printf("****************************\n");
    printf(">>>\n");
    printf(" ----------------------------------------------------------------------------------\n");
    printf("|       |     ����     |     ����     |     �е�     |     ����     |    ������    |\n");
    printf(" ----------------------------------------------------------------------------------\n");
    int excellent, good, medium, pass, fail;
    for (int i = 0; i < g_subjectNum; ++i) {
        excellent = 0, good = 0, medium = 0, pass = 0, fail = 0;
        STU *temp = head->next;  //ͷ��㲻�������
        while (temp != head) {
            if (temp->score[i].subjectScore >= 90) {
                excellent++;
            } else if (temp->score[i].subjectScore >= 80) {
                good++;
            } else if (temp->score[i].subjectScore >= 70) {
                medium++;
            } else if (temp->score[i].subjectScore >= 60) {
                pass++;
            } else {
                fail++;
            }
            temp = temp->next;
        }
        printf("| ��%d�� | %4d��/%4.1f%% | %4d��/%4.1f%% | %4d��/%4.1f%% | %4d��/%4.1f%% | %4d��/%4.1f%% |\n",
               i + 1, excellent, (double) excellent / g_studentNum * 100, good, (double) good / g_studentNum * 100,
               medium, (double) medium / g_studentNum * 100, pass, (double) pass / g_studentNum * 100,
               fail, (double) fail / g_studentNum * 100);
        printf(" ----------------------------------------------------------------------------------\n");
    }
}

//�������ܣ����ȫ����Ϣ
void printAll(STU *head) {
    system("cls");
    if (doubleListIsEmpty(head) == 1)   //�ж������Ƿ�Ϊ��
        return;
    printf("**************\n");
    printf("*���ȫ����Ϣ*\n");
    printf("**************\n");
    printf(">>>\n");
    doubleListPrint(head);
    printTotalAndAverageScore(head);
}
//��ѯ���ֽ���