#include <stdio.h>
#include <stdlib.h>

int* max_of_array(int* ary, int len)
{
   int* max=ary;
   for(int i=0;i<len;i++){
       if(*max<*(ary+i)){
            max=(ary+i);
       }
   }
   return max;
}
int main()
{
    int ary[10];
    int len;

    printf("Number of input(1~10):");
    scanf("%d",&len);
    printf("Input numbers:");
    for(int i=0;i<len;i++){
        scanf("%d",(ary+i));
    }

    printf("%d is maximum value of this array.\n",*max_of_array(ary,len));

    return 0;
}
