#include <stdio.h>
/* 1�� */
int main(void)
{
    int su, cnt, hap = 0;

re:
    printf("������ �Է�: ");
    scanf_s("%d", &su, sizeof(su));
    if (su > 0) {
        for (cnt = 1; cnt <= su; cnt++) {
            if (cnt % 3 == 0) {
                hap = hap + cnt;
            }
        }
        printf("1���� %d���� 3�� ��� ���� �հ�� %d\n", su, hap);
        return 0;
    } else {
        printf("���� ������ %d��(��) ������� �ʽ��ϴ�.\n", su);
        printf("���� �������� �ٽ� �Է��ϼ���.\n");
        goto re;
    }
}