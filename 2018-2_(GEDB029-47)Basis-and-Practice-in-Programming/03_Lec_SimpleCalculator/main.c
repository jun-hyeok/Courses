#include <stdio.h>
#include <stdlib.h>

int sum()
{
    int num, res=0;
    printf("Sumation\n");
    while(1){
        printf("Input numbers. '-1' will end input:");
        scanf("%d",&num);
        if (num==-1){
            printf("Sum: %d\n",res);
            break;
        }
        else{
            res+=num;
            continue;
        }
    }
    return;
}

int mul()
{
    int num, res=1;
    printf("Multiplication\n");
    while(1){
        printf("Input numbers. '-1' will end input:");
        scanf("%d",&num);
        if (num==-1){
            printf("Multiplication: %d\n",res);
            break;
        }
        else{
            res*=num;
            continue;
        }
    }
    return;
}

int r_sum()
{
    int num, min, max, res=0;
    printf("Range summation\n");
    printf("Input min. max numbers(ex:1 10):");
    scanf("%d%d",&min,&max);
    for(num=min;num<=max;num++){
            res+=num;
        }
    printf("Range sum: %d\n",res);

    return;
}

int r_mul()
{
    int num, min, max, res=1;
    printf("Range multiplication\n");
    printf("Input min. max. numbers(ex:1 10):");
    scanf("%d%d",&min,&max);
    for(num=min;num<=max;num++){
            res*=num;
        }
    printf("Range sum: %d\n",res);

    return;
}

int main()
{
    char opt;
    int flag=1;
    while(flag){
        printf("usage-'s'um, 'm'ul, 'r'ange sum, 'R'ange mul, e'x'it:");
        scanf(" %c",&opt);

        switch(opt){
            case 's':
                sum();
                break;
            case 'm':
                mul();
                break;
            case 'r':
                r_sum();
                break;
            case 'R':
                r_mul();
                break;
            case 'x':
                flag=0;
                printf("Bye bye~\n");
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }


    return 0;
}
