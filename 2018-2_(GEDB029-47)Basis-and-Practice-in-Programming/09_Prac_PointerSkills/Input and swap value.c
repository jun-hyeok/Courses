#include <stdio.h>


void input(int *p)
{
    do{
        printf("Input a positive number:");
        scanf("%d",p);
        if(*p<1)
            printf("You have to input a positive value!\n\n");
    }while(*p<1);
}

void swap(int *p1,int *p2)
{
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

int main()
{
	int i, j;

	input(&i);
	input(&j);

	printf("\ni : %d\n",i);
	printf("j : %d\n\n",j);

	swap(&i,&j);

	printf("i : %d\n",i);
	printf("j : %d\n",j);

	return 0;
}
