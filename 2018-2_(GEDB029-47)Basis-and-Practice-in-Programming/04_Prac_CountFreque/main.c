#include <stdio.h>
#include <stdlib.h>

int main()
{
    int freq[10]={0}, num;
    while(1){
        printf("Input number(range of 0 to 9 or exit program) :");
        scanf("%d",&num);
        if(num>=0&&num<=9){
            freq[num]++;
        }
        else{
            for(int i=0;i<10;i++){
                printf("%d is entered %d times\n",i,freq[i]);
            }
            break;
        }
    }
    return 0;
}
