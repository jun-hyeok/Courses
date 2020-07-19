#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int ary[5], num, idx=-1;
    srand(time(0));
    for(int i=0;i<5;i++){
        ary[i]=rand()%20+1;
        printf("%d ",ary[i]);
    }
    printf("\nInput a number you want to find : ");
    scanf("%d",&num);
    for(int i=0;i<5;i++){
        if(ary[i]==num){
            idx=i;
            break;
        }
    }
    printf("The number's index is %d\n",idx);
    return 0;
}
