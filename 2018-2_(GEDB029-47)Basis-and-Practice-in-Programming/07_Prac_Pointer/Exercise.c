#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int AssignArr(int arr[], int arr_num)
{
    for(int i=0;i<arr_num;i++){
        arr[i]=rand()%10+1;
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void CompareArr(int arr[], int arr_num, float *avg, int *count)
{
    int sum=0;
    for(int i=0;i<arr_num;i++){
        sum+=arr[i];
    }
    *avg=sum/(float)arr_num;
    for(int i=0;i<arr_num;i++){
        if(arr[i]>*avg){
            (*count)++;
        }
    }
}

int main()
{
    int arr[10];
    int arr_num, cnt_num=0;
    float avg_num;
    srand(time(0));
    printf("input the length of Array \n");
    scanf("%d",&arr_num);
    AssignArr(arr,arr_num);
    CompareArr(arr,arr_num,&avg_num,&cnt_num);
    printf("the number of components bigger than average value %f is %d \n",avg_num,cnt_num);

    return 0;
}
