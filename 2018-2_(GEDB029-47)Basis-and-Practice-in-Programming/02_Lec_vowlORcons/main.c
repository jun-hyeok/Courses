#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch, cutoff[100];
    int i;
    for (i=1;i<=5;i++)
    {
        do
        {
            printf("Input a character:");
            scanf(" %c%s",&ch,cutoff);
            printf("\n");
        } while (!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        {
            printf("%c is a vowel\n",ch);
        }
        else
        {
            printf("%c is a constant\n",ch);
        }
    }
    return 0;
}
