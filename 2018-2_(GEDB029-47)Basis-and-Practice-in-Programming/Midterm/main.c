#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int password;
    printf("Input Password:");
    scanf("%d",&password);

    int line[3][10], dial_status[3];
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            line[i][j]=j;
        }
    }
    printf("Your initial state:\n");
    for(int i=0;i<3;i++){
        printf("Line#%d-",i+1);
        for(int j=0;j<10;j++){
            printf("%d",line[i][j]);
        }
        printf("\n");
        for(int k=0;k<3;k++){
            dial_status[k]=line[i][0];
        }
    }

    printf("Randomizing your lock\n");
    int l_temp;
    for(int i=0;i<3;i++){
        int l_shift_num=0;
        dial_status[i]=rand()%10;
        printf("Current Number of Line#%d-%d\n",i+1,dial_status[i]);
        while(l_shift_num<dial_status[i]){
            l_temp=line[i][0];
            for(int j=0;j<9;j++){
                line[i][j]=line[i][j+1];
            }
            line[i][9]=l_temp;
            l_shift_num++;
        }
    }
    while(1){
        int line_num, r_shift_num, r_temp, i=0;
        printf("Input the line number to shift to right:");
        scanf("%d",&line_num);
        printf("How many times do you want to shift to the right?");
        scanf("%d",r_shift_num);
        while(i<r_shift_num){
            r_temp=line[line_num-1][9];
            for(int j=0;j<9;j++){
                line[line_num-1][9-j]=line[line_num-1][8-j];
            }
            line[line_num-1][0]=r_temp;
        }

        for(int i=0;i<3;i++){
            printf("Line#%d-",i+1);
            for(int j=0;j<10;j++){
                printf("%d",line[i][j]);
            }
            printf("\n");
        }
        if(dial_status[0]==password/100){
            if(dial_status[1]==(password%100)/10){
                 if (dial_status[2]==password%10){
                    break;
                 }
            }
        }
    }
    printf("Right password\n");
    return 0;
}
