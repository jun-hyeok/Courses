#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str[21] = "THIS is string";
    char str2[21];
    printf("input compared string : ");
    gets(str2);
    int flag=1;
    while(flag){
        puts(str);
        puts(str2);
        if(*str!=*str2){
            printf("Different!\n\n");
            printf("input compared string : ");
            gets(str2);
        }
        else if(*str==*str2){
            printf("Same!");
            flag=0;
        }
    }

//    int i=0;
//    while(str[i]!='\0'){
//        if(str[i]==str2[i]){
//            i++;
//            continue;
//        }
//        else{
//            i++;
//            check=1;
//            break;
//        }
//    }

    return 0;
}
