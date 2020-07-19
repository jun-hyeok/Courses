#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    FILE *fp = fopen("prac1.txt", "r");

    int check=0;
    fgets(str,100,fp);
    while(fscanf(fp,"%s",str)!=EOF){
        if(check==0){
            check=1;
            printf("Student ID: %s ,",str);
        }else{
            check=0;
            printf("Name:%s\n",str);
        }
    }
    fclose(fp);
}
