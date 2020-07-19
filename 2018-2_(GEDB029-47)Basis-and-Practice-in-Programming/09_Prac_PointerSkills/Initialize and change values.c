#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=10, j=15;
    int *pi, *pj;

    pi=&i;
    pj=&j;

    printf("-Before Changing Values-\n");
    printf("Value Of '*pi':%d\n",*pi);
    printf("Value Of '*pj':%d\n\n",*pj);
    printf("Address of 'i':%p\n",&i);
    printf("Address of 'j':%p\n\n",&j);
    printf("Value of 'pi':%p\n",pi);
    printf("Value of 'pj':%p\n\n",pj);
    *pi=20;
    *pj=25;
    printf("-After Changing Values-\n");
    printf("Value Of '*pi':%d\n",*pi);
    printf("Value Of '*pj':%d\n\n",*pj);
    printf("Address of 'i':%p\n",&i);
    printf("Address of 'j':%p\n\n",&j);
    printf("Value of 'pi':%p\n",pi);
    printf("Value of 'pj':%p\n\n",pj);

    return 0;
}
