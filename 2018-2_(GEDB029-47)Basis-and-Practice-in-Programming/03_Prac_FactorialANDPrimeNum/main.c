#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{

}
int check_prime(int num)
{

}
int exit()
{
    printf("Good bye~\n");
    break;
}
int main()
{
    char select;
    int num;
    while(i){
        printf("'f'actorial, 'c'heck_prime, e'x'it:");
        scanf("%c",&select);
        printf("Input the number:");
        scanf("d",&num);
        switch(select){
            case 'f':
                factorial(num);
            case 'c':
                check_prime(num);
            case 'x':
                exit();
        }
    }

    return 0;
}
