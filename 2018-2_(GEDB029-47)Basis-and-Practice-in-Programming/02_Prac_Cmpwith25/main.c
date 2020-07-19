#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input_number;
    int num=0;
    printf("start the program\n");
    while(num<5){
        printf("Plaese input the number:");
        scanf("%d",&input_number);

        if (input_number>25){
            printf("%d is bigger than 25\n",input_number);
        }
        else if(input_number==25){
            printf("%d is equal to 25\n",input_number);
        }

        else{
            printf("%d is smaller than 25\n",input_number);
        }
        num++;
    }
    printf("end the program");
    return 0;
}
