#include <stdio.h>

int main(void)
{
    //예제 4-2 자료형의 유효 범위 초과 - 오버플로 발생

    signed short num1, num2;
    num1 = 32767;
    num2 = 32767 + 8;

    printf("signed short형 유효 범위 : -32768 ~ 32767\n");
    printf("1.변수 num1 = 32767은 정상 출력 : %7d\n", num1);
    printf("2.변수 num2 = 32767 + 8은 오버플로 : %7d\n", num2);
    return 0;
}