#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void min_max(int number[], int size)
{
    int *min=number, *max=number;
    for(int *p=number;p<number+size;p++){
        if (*min>=*p)
            min=p;
        if(*max<=*p)
            max=p;
    }
   printf("%d %d\n",*min,*max);

}
void swap(char *a, char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void reverse(char *front, char *back)
{
//    if(front>=back)
//        return;
//    else{
//        swap(front,back);
//        reverse(++front,--back);
//    }
    while(front<back)
        swap(front++,back--);
}
void input_reverse()
{
    char ch=getchar();
    if(ch!='\n'){
        input_reverse();
        printf("%c",ch);
    }
}
void str_reverse()
{
    char *p_s, str[20];
    p_s=str;
    gets(str);
    int i=0;
    while(*p_s!='\0'){
        if(*p_s!=' '){
            *(str+i++)=*p_s;
        }
        p_s++;
    }
    str[i]='\0';
    reverse(str,str+strlen(str)-1);
    puts(str);
    p_s=str;
    while(*p_s!='\0'){
        int i=0;
        while(*(p_s+i)!='\0'){
            printf("%c",*(p_s+i));
            i++;
        }
        printf("\n");
        p_s++;
    }
}
int main()
{
    str_reverse();
    int size;
    #if 0
    printf("what size?");
    scanf("%d",&size);
    int number[size];
    for(int i=0;i<size;i++){
        printf("number:");
        scanf("%d",&number[i]);
    }
    for(int i=0;i<size;i++){
        printf("%d",*(number+i));
    }
    printf("\n");
    reverse(number,number+size-1);
    for(int i=0;i<size;i++){
        printf("%d",*(number+i));
    }
    printf("\n");
    min_max(number,size);
    printf("input\n");
    #endif
    return 0;
}
