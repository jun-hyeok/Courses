#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, gcd;
    printf("Input two number:");
    scanf("%d %d",&num1,&num2);
    for(int i=1;(i<=num1)&&(i<=num2);i++){
        if((num1%i==0)&&(num2%i==0))gcd=i;
    }
    printf("Greatest common divisor of two number is %d",gcd);
    return 0;
}
