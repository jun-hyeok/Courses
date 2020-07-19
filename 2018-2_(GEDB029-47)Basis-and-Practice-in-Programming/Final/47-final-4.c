#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char ch;
    int size=1;
    int index=0;
    char *str=(char*)malloc(sizeof(char));

    printf("Enter a string in one line : ");
    while(1){
        ch=getchar();
        if(ch=='\n')
            break;
        else
            *(str+index++)=ch;
        str=(char*)realloc((char*)str,sizeof(char)*(++size));
    }
    str[index]='\0';
    printf("Size of str : %d\n",size);
    printf("Length of str : %d\n",strlen(str));
    printf("Content of str : %s\n",str);

    return 0;
}
