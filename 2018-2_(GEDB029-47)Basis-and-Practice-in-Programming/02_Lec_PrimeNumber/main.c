#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i=2, res;
    printf("Enter a number:");
    scanf("%d",&num);
    for (int i=2;i>=2;i++){
        res=num%i;
        if(res==0){
            if(num==i){
                printf("The number is a prime number.\n");
                break;
            }
            else{
                printf("The number is not a prime number.\n");
                break;
            }
        }
        else{
            continue;
        }
    }
    while(1){
        res=num%i;
        if(res==0){
            if(num==i){
                printf("The number is a prime number.\n");
                break;
            }
            else{
                printf("The number is not a prime number.\n");
                break;
            }
        }
        else{
            i++;
            continue;
        }
    }
    return 0;
}
