#include <stdio.h>
#include <stdlib.h>

void reverse(char* front,char* back)
{
    if(front>=back) return;
    else{
        char temp=*front;
        *front=*back;
        *back=temp;
        reverse(++front,--back);
    }

}

int main()
{
    char ary[11];
    int len;

    printf("Length of string(1~10):");
    scanf("%d",&len);
    printf("Input string:");
    scanf("%s",ary);

    reverse(ary,ary+len-1);

    printf("reversed:%s\n",ary);

    return 0;
}
