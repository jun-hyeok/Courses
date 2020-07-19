#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *pA, *pB;

    srand(time(0));
    int a, b;
    pA=&a;
    pB=&b;
    *pA=rand()%45+1;
    *pB=rand()%45+1;

    printf("pA is %d, pB is %d\n", *pA,*pB);

    return 0;
}
