#include <stdio.h>
#include <stdlib.h>
#define ROOM 15
/* 3�� */
int main(void)
{
    char alpha;
    int choice;
    int hotel[ROOM] = { 0 };
    do {
        printf("ȣ���� �����Ͻðڽ��ϱ�?(Y/N) : ");
        scanf_s("%c", &alpha, sizeof(alpha));
        getchar();
        switch (alpha) {
        case 'Y':
        case 'y':
            printf("ȣ�� ��ȣ : ");
            for (int i = 0; i < ROOM; i++) {
                printf("%2d ", i + 1);
            }
            printf("\n���� ��Ȳ : ");
            for (int i = 0; i < ROOM; i++) {
                printf("%2d ", hotel[i]);
            }
        re:
            printf("\nȣ�� ����(1~15) : ");
            scanf_s("%d", &choice, sizeof(choice));
            getchar();
            if (choice >= 1 && choice <= ROOM) {
                if (hotel[choice - 1] == 1) {
                    printf("�̹� ����� ���Դϴ�.\n");
                    printf("�ٽ� ������ �ּ���.\n");
                    goto re;
                }
                printf("���� �Ϸ�!\n\n");
                hotel[choice - 1] = 1;
                break;
            } else {
                printf("��ȿ���� �ʴ� ������ ���Դϴ�.\n");
                printf("�ٽ��Է� ���ּ���.\n");
                goto re;
            }

        case 'N':
        case 'n':
            printf("���α׷��� �����մϴ�.\n");
            return 0;
            break;
        default:
            printf("���ĺ� �Է� ����!\n");
            printf("���ĺ��� ��� ���� ���� ���� Y �Ǵ� N�� ����մϴ�.\n");
            printf("���ĺ��� �ٽ� �Է��Ͻÿ�.\n\n");
            break;
        }
    } while (1);
}