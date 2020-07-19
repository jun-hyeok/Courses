#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, count=0;
    while(1){
        printf("Input the number (0:exit) :");
        scanf("%d",&num);
        if(num==0) break;
        for(int i=1;i<=num;i++){
            if(num%i==0){
                printf("%d is divisor of %d\n",i,num);
                count++;
            }
        }
        printf("%d's number of divisor is %d\n",num,count);

    }
    return 0;
}
