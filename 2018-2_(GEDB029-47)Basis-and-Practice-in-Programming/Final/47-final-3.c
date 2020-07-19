#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp=fopen("words.txt","r");
    FILE *fp_new=fopen("words_new.txt","w");
    char ch;
    while((ch=fgetc(fp))!=EOF){
        if('a'<=ch&&ch<='z')
            ch=ch-'a'+'A';
        else if('A'<=ch&&ch<='Z')
            ch=ch-'A'+'a';
        fputc(ch,fp_new);

    }
    fclose(fp);
    fclose(fp_new);
}
