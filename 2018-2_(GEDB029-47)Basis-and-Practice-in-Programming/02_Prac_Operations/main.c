#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a,b;
    printf("a:");
    scanf("%d",&a);

    printf("b:");
    scanf("%d",&b);

    printf("\n");

    printf("Addition: %d\n",a+b);
    printf("Subtraction: %d\n",a-b);
    printf("Multiplication: %d\n",a*b);
    printf("Division: %f\n",a/b);
    printf("Remaining: %d\n",a%b);

    return 0;
}
