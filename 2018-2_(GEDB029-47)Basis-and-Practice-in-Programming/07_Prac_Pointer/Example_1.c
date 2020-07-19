#include<stdio.h>

int main()
{
    int A=10;
    char B='P';
    double C=9.59;

    int *pA=&A;
    char*pB=&B;
    double *pC=&C;

    printf("pA:%p\npB:%p\npC:%p\n\n",pA,pB,pC);
    printf("&A:%p\n&B:%p\n&C:%p\n\n",&A,&B,&C);
    printf("sizeof(pA):%d\nsizeof(pB):%d\nsizeof(pC):%d\n\n",sizeof(pA),sizeof(pB),sizeof(pC));
    printf("pA:%d\npB:%c\npC:%lf\n\n",*pA,*pB,*pC);
    printf("sizeof(*pA):%d\nsizeof(*pB):%d\nsizeof(*pC):%d\n\n",sizeof(*pA),sizeof(*pB),sizeof(*pC));
    printf("&pA:%p\n&pB:%p\n&pC:%p\n\n",&pA,&pB,&pC);

    return 0;
}
