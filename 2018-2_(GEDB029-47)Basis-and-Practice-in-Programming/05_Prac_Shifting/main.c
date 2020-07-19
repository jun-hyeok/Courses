#include <stdio.h>
#include <stdlib.h>

int max_value(int ary[],int k)
{
    int max_idx=0;
    for(int i=0;i<k;i++){
        if(ary[i]>ary[max_idx]){
            max_idx=i;
        }
    }
    return max_idx;
}
int r_shift(int ary[],int i)
{
    int temp=ary[i-1];
    while(--i>0){
        ary[i]=ary[i-1];
    }
    ary[0]=temp;
}
int l_shift(int ary[],int i)
{
    int temp=ary[0], k=i;
    while(--i>0){
        ary[k-i-1]=ary[k-i];
    }
    ary[k-1]=temp;
}
int print_ary(int ary[],int k)
{
    for(int i=0;i<k;i++){
        printf("%3d",ary[i]);
    }
    printf("\n");
}
int main()
{
    //max_value_index
    printf("====max_value_index====\n");
    int n_size, n_ary[100];
    printf("Input size number of array: ");
    scanf("%d",&n_size);
    for(int i=0;i<n_size;i++){
        printf("Input %dth element: ",i+1);
        scanf("%d",&n_ary[i]);
    }
    printf("max value's index is %d\n\n",max_value(n_ary,n_size));

    //shift to right
    printf("====shift to right====\n");
    print_ary(n_ary,n_size);
    r_shift(n_ary,n_size);
    n_ary[0]=0;
    print_ary(n_ary,n_size);

    //circular_shift_array
    char opt;
    int l_temp,r_temp,flag=1;
    printf("====circular_shift_array====\n");
    print_ary(n_ary,n_size);
    while(flag){
        printf("Which direction do you want 'l'eft or 'r'ight? ");
        scanf(" %c",&opt);
        switch(opt){
            case 'l':
                l_shift(n_ary,n_size);
                break;
            case 'r':
                r_shift(n_ary,n_size);
                break;
            default:
                flag=0;
                break;
        }
        print_ary(n_ary,n_size);
    }
    return 0;
}
