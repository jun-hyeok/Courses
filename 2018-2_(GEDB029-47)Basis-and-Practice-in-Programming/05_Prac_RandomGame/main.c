#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


void initializerArray(int ary[])
{
    for(int i=0;i<N;i++){
        ary[i]=i;
    }
}
void printArray(int ary[])
{
    for(int i=0;i<N;i++){
        printf("%3d",ary[i]);
    }
    printf("\n");
}
void r_shift(int ary[])
{
    int i=N;
    int temp=ary[i-1];
    while(--i>0){
        ary[i]=ary[i-1];
    }
    ary[0]=temp;
}
void l_shift(int ary[])
{
    int temp=ary[0], i=N;
    while(++i<N){
        ary[i-1]=ary[i];
    }
    ary[N]=temp;
}
void swap(int ary[], int idx1, int idx2)
{
    int temp;
    temp=ary[idx1];
    ary[idx1]=ary[idx2];
    ary[idx2]=temp;
}
void shuffle(int ary[])
{
    int n=0;
    while(n++<100){
    swap(ary,rand()%N,rand()%N);
    }
}
void randomPick(int ary[], int ary_state[])
{
    int pick;
    for(int i=0;i<N;i++){
        printf("turn %d:",i+1);
        while(1){
            pick=rand()%N;
            if (ary_state[pick]==0)
                ary_state[pick]=1;
                printState(ary[],ary_state[]);
        }
    }
}
void printState(int ary[],int ary_state[])
{

}
void main()
{
    int deck[N];
    int deck_state[N]={0};
    srand((unsigned int)time(0));

    printf("Initial Deck:");
    initializerArray(deck);
    printArray(deck);

    printf("Shuffled Deck:");
    shuffle(deck);
    printArray(deck);

    randomPick(deck,deck_state);
}
/*Practice
void main()
{
    int times, line[N];
    initializerArray(line);
    printf("Initial Line :");
    printArray(line);

    printf("How many times to shift to right:");
    scanf("%d",&times);
    while(times-->0){
    r_shift(line);
    }
    printf("Right Shift Line:");
    printArray(line);

    printf("How many times to shift to left:");
    scanf("%d",&times);
    while(times-->0){
    l_shift(line);
    }
    printf("Left Shift Line:");
    printArray(line);
    return 0;
}
*/
