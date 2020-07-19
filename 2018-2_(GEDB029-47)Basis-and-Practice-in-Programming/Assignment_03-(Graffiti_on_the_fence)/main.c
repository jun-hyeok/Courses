#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

void make_series(int opt, int N, int ary[])
{
    if(opt==1){
        for(int i=0;i<N*N;i++){
            ary[i]=i+1;
        }
    }
    else{
        for(int i=0;i<N*N;i++){
            ary[i]=fibonacci(i+1);
        }
    }
}

void print_graffiti(int ary[], int N)
{
    int k=0, snail[N][N], L=N;
    for(int i=0;i<N/2;i++){
        for(int j=0;j<L-1;j++){
            snail[i][i+j]=ary[k+j];
            snail[i+j][N-1-i]=ary[k+(L-1)+j];
            snail[N-1-i][N-1-i-j]=ary[k+2*(L-1)+j];
            snail[N-1-i-j][i]=ary[k+3*(L-1)+j];
        }
        k+=4*(L-1);
        L-=2;
    }
    if(N%2!=0)
        snail[N/2][N/2]=ary[N*N-1];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
                printf("%8d ",snail[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int opt, size;
    printf("=================================================================\n");
    printf("Oh, there is a spiral shape graffiti on Market Minguinho's fence!\n");
    printf("Hmm.. look at that. It looks like sequence of numbers.\n");
    printf("I think is ...\n");
    printf("1. Natural numbers (1, 2, 3, 4, 5, 6, 7 ...)\n");
    printf("2. Fibonacci numbers (1, 1, 2, 3, 5, 8 ...)\n(Select one)\n");
    printf("=================================================================\n");
    do{
        scanf("%d",&opt);
    }while(!(opt==1||opt==2));
    printf("=================================================================\n");
    printf("How big is the graffiti? (Enter the size of array. min:3/max:6)\n");
    printf("=================================================================\n");
    scanf("%d",&size);
    int series[size*size];
    make_series(opt,size,series);
    print_graffiti(series,size);
    return 0;
}
