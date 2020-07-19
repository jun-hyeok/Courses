#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[6] = "hello";
    char str2[] = {'H','e','l','l','o','W','o','r','l','d','\0'};
    char* pointer = str2;
    printf("[%s]\n", str);
    printf("[%s]\n", str2);
    printf("[%s]\n\n", pointer);

//    for(int i=0;i<11;i++){
//        printf("%s\n",pointer++);
//    }

    while(*pointer!='\0'){
        printf("%s\n",pointer++);
    }

    return 0;
}
