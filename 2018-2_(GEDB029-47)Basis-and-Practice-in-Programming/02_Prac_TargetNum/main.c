#include <stdio.h>
#include <stdlib.h>

int main()
{

    int target_num, input_num, sum=0;
    printf("What is target number?:");
    scanf("%d",&target_num);
    while (sum<=target_num){
        printf("Please input the number:");
        scanf("%d",&input_num);
        sum+=input_num;
        printf("Sum of all of input number is %d\n",sum);
    }
    printf("Now %d is bigger than %d. end program.\n",sum,target_num);

    return 0;
}
