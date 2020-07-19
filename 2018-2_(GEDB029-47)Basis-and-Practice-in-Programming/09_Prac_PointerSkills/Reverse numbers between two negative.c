#include <stdio.h>
void reverse_between_two_negative(int *ary, int size)
{
    int *first=0, *second=0;
    for(int i=0;i<size;i++){
        if(*(ary+i)<0){
            if(first==0){
                first=ary+i;
            }
            else{
                second=ary+i;
                break;
            }
        }
    }
    while(first<second){
        int temp;
        temp=*first;
        *first=*second;
        *second=temp;
        first++;
        second--;
    }
}

int main()
{
    int ary[10] = { 7, 6, 11, -1, 10, 8, 4, 1, -10, 19 };
    printf("-Before change-\n");
    for (int i=0;i<10;i++)
        printf("%d ",ary[i]);
    reverse_between_two_negative(ary, 10);
    printf("\n-After change-\n");
    for (int i=0;i<10;i++)
        printf("%d ",ary[i]);
    printf("\n");
    return 0;
}
