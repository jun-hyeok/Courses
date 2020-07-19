#include <stdio.h>
#include <stdlib.h>

char square[10][10];

int make_square(int num)
{
    if(num==0){
        return 0;
    }
    if(num%2==0){
        for(int i=0;i<num;i++){
            square[i][num-1]='+';
            square[num-1][i]='+';
        }
    }
    else{
        for(int j=0;j<num;j++){
            square[j][num-1]='.';
            square[num-1][j]='.';
        }
    }
    make_square(num-1);
}
int main()
{
    make_square(10);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%2c",square[i][j]);
        }
        printf("\n");
    }

    return 0;
}
