#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str[21];
    int i = 0;

    while(1){
        char ch = getchar();
        if(ch=='\0'||i>=20){
            break;
        }
        if('A'<=ch&&ch<='Z'){
            continue;
        }
        else if(('a'<=ch&&ch<='z')||ch==32){
            str[i++]=ch;
        }
    }
    str[i] = '\0';
    puts(str);

    return 0;
}
