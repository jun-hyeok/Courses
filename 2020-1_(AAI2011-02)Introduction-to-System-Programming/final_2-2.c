#include <stdio.h>
#include <stdlib.h>

void score_fun(void);
void grade_fun(int total);
void alpha_err(char alpha);
void jumsu_err(int jumsu);
void end_fun(char alpha);

int main(void)
{
    char alpha;
    printf("[ main( ) �Լ� ���� ]\n");
    printf("���α׷��� �����Ͻðڽ��ϱ�?(Yes/No) : ");
    scanf_s("%c", &alpha, sizeof(alpha));
    getchar();
    switch (alpha) {
    case 'Y':
    case 'y':
        score_fun();
        break;
    case 'N':
    case 'n':
        end_fun(alpha);
        break;
    default:
        alpha_err(alpha);
        break;
    }
}
void score_fun(void)
{
    int jumsu_1, jumsu_2, total;
re:
    printf("[ score_fun( ) �Լ� ���� ]\n");
    printf("1����� �����Է�(50�� ����) : ");
    scanf_s("%d", &jumsu_1, sizeof(jumsu_1));
    getchar();
    printf("2����� �����Է�(50�� ����) : ");
    scanf_s("%d", &jumsu_2, sizeof(jumsu_2));
    getchar();
    if (jumsu_1 < 0 || jumsu_1 > 50) {
        jumsu_err(jumsu_1);
        goto re;

    } else if (jumsu_2 < 0 || jumsu_2 > 50) {
        jumsu_err(jumsu_2);
        goto re;
    } else {
        total = jumsu_1 + jumsu_2;
        grade_fun(total);
    }
}
void grade_fun(int total)
{
    printf("[ grade_fun( ) �Լ� ���� ]\n");
    printf("score_fun( ) �Լ����� ���޹��� ��: %d", total);
    if (total >= 90 && total <= 100) {
        printf("��� : ��\n");
    } else if (total >= 70 && total < 90) {
        printf("��� : ��\n");
    } else if (total >= 0 && total < 70) {
        printf("��� : ��\n");
    } else {
        jumsu_err(total);
    }
    main();
}
void alpha_err(char alpha)
{
    printf("[ alpha_err( ) �Լ� ���� ]\n");
    printf("%c�� �߸��� �Է��Դϴ�.\n", alpha);
    main();
}
void jumsu_err(int jumsu)
{
    printf("[ jumsu_err( ) �Լ� ���� ]\n");
    printf("%d�� ��ȿ���� ���� ������ ���Դϴ�.\n", jumsu);
    score_fun();
}
void end_fun(char alpha)
{
    printf("[ end_fun( ) �Լ� ���� ]\n");
    printf("main( ) �Լ����� ���α׷� ���Ḧ ��û�߽��ϴ�.\n");
    printf("���ĺ� \"%c\"�� ���޹޾� ���α׷��� �����մϴ�!!", alpha);
    exit(0);
}
