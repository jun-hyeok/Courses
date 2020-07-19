#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    int toEng;
    int arr[10] = {3525234, 64124525, 84363472, 5457574, 53453, 8734724, 934675, 74835, 34580, 12343845};
    double answer = 1;
    char ch;
    FILE *fp;

    printf("1. Input two integer value and print sum of them.\n");
    scanf("%d %d",&num1,&num2);
    printf("%d+%d=%d\n",num1,num2,num1+num2);
    printf("2. Input one number (1~3) and print it with English.\n");
    scanf("%d",&toEng);
    switch(toEng){
        case 1:
            printf("One\n");
            break;
        case 2:
            printf("Two\n");
            break;
        case 3:
            printf("Three\n");
            break;
        default:
            printf("Input 1~3\n");
            break;
    }
    printf("3. print product(*) of arr[10]'s odd element.\n");
    for(int i=0;i<10;i++){
        if(arr[1]%2!=0)
            answer*=arr[i];
    }
    printf("product is %.6lf\n",answer);
    printf("4. Read \"47-final-1-text.txt\" and print all\n");
    fp=fopen("47-final-1-text.txt","r");
    char str[100];
    while(fgets(str,sizeof(str),fp)!=0){
        puts(str);
    }

    return 0;
}
