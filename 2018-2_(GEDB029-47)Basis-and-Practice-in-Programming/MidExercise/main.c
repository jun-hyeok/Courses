#include <stdio.h>
#include <stdlib.h>

void execute_range_summation(int min, int max)
{
    int sum = 0;
    for (int i = min; i <= max; i++)
        sum += i;
    printf("Range sum: %d\n", sum);
    return;
}
int main()
{
    char c;
    while (1) {
        printf("usage-'s'um, 'm'ul, 'r'ange sum, 'R'ange mul, e'x'it : ");
        scanf(" %c", &c);
        if (c == 'r') {
            int min, max;
            printf("Input min, max numbers (ex: 1 10):");
            scanf(" %d %d", execute_range_summation(&min, &max));
        }
        if (c == 'x') {
            printf("Good Bye\n");
            break;
        }
    }
    return 0;
}
