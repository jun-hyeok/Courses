#include <stdio.h>

void find_two_negative(int *ary, int size)
{
    int idx_dif=0;
    for(int i=0;i<size;i++){
        if(*(ary+i)<0){
            *(ary+i)=0;
            idx_dif-=i;
            idx_dif*=-1;
        }
    }
    printf("\n\nThe difference between two negative's indexes is %d\n\n",idx_dif);
}

int main()
{
    int ary[10] = { 7, 6, 11, -1, 10, 8, 4, 1, -10, 19 };
    printf("-Before change-\n");
    for (int i=0;i<10;i++)
        printf("%d ",ary[i]);
    find_two_negative(ary,10);
    printf("-After change-\n");
    for (int i=0;i<10;i++)
        printf("%d ",ary[i]);
    printf("\n");
    return 0;
}
