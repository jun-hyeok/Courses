#include <stdio.h>
#include <stdlib.h>
int sum_of_max_min_value(int ary[])
{
    int idx_M=0, idx_m=0, sum;
    for(int i=0;i<5;i++){
        if(ary[i]>ary[idx_M]){
            idx_M=i;
        }
    }
    for(int i=0;i<5;i++){
    if(ary[i]<ary[idx_m]){
        idx_m=i;
        }
    }
    sum=ary[idx_M]+ary[idx_m];
    printf("The summation of Maximum value and Minimum value is %d\n",sum);
}

int main()
{
    int ary[5];
    printf("Input the numbers: ");
    for(int i=0;i<5;i++){
        scanf("%d",&ary[i]);
    }
    sum_of_max_min_value(ary);
    return 0;
}
