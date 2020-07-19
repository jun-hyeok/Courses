#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[20];
    scanf("%s",str);
    for(int i=0;i<20;i++){
        if('a'<=str[i]&&str[i]<='z'){
            str[i]=str[i]-'a'+'A';
        }
        if('A'<=str[i]&&str[i]<='Z'){
            str[i]=str[i]-'A'+'a';
        }
    }
    printf("%s",str);
    return 0;
}
