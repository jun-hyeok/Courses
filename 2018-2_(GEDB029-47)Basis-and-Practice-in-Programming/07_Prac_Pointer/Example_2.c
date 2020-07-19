#include <stdio.h>

int main()
{
    int n1=100, n2=200;
    int *ptr1=&n1, *ptr2=&n2;

    printf("%d %d %p %p\n",n1,n2,ptr1,ptr2);
    *ptr1=34;
    printf("%d %d %p %p\n",n1,n2,ptr1,ptr2);
    ptr1=&n2;
    printf("%d %d %p %p\n",n1,n2,ptr1,ptr2);
    *ptr1=*ptr2+30-*ptr1;
    printf("%d %d %p %p\n",n1,n2,ptr1,ptr2);

    return 0;
}
