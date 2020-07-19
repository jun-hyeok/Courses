#include <stdio.h>
#include <stdlib.h>

int main()
{
    char word[20];
    int vowel_num=0;

    printf("Input the word : ");
    gets(word);
    for(int i=0;i<20;i++){
        if((word[i]=='a')||(word[i]=='e')||(word[i]=='i')||(word[i]=='o')||(word[i]=='u'))
            vowel_num++;
    }
    printf("%s have %d of vowels",word,vowel_num);
    return 0;
}

