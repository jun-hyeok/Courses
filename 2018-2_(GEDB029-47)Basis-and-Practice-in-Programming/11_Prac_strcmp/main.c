#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100] = "hello c world what is the index of word you want";
    char str2[20];

    printf("input the string :");
    scanf("%s", str2);

    int i=0;
    while(i<strlen(str)){
        if(!strncmp(str+i,str2,strlen(str2))){
            printf("index is %d",i+1);
            break;
        }
        else{
            i++;
        }
    }
    if(i==strlen(str))
        printf("there is no matched string");

    return 0;
}
