#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int info_line(int ary[],int n)
{
    int opt;
    printf(" %c",n+65);
    opt=ary[0];
    switch(opt){
        case 1:
            printf("  |    AUTO   |");
            break;
        case 2:
            printf("  | SEMI-AUTO |");
            break;
        case 3:
            printf("  |   MANUAL  |");
            break;
    }
    for(int i=1;i<=6;i++){
        printf("%4d",ary[i]);
    }
    printf("\n");
}
int NEW_info_line(int ary[][7],int n)
{
    int opt;
    printf(" %c",n+65);
    opt=ary[n][0];
    switch(opt){
        case 1:
            printf("  |    AUTO   |");
            break;
        case 2:
            printf("  | SEMI-AUTO |");
            break;
        case 3:
            printf("  |   MANUAL  |");
            break;
    }
    for(int i=1;i<=6;i++){
        printf("%4d",ary[n][i]);
    }
    printf("\n");
}

int manual_selc(int ary[],int k) /*k for manual*/
{
    int i, j, temp;
    for(i=1;i<=k;i++){
        printf("Input %dth number between 1~45\n",i);
        scanf("%d",&temp);
        if(temp>=1&&temp<=45){
            for(j=1;j<i;j++){
                if(temp==ary[j]){
                    printf("Duplicate number! Please select a different number.\n");
                    i--;
                    break;
                }
            }
            if(i==j){
                ary[i]=temp;
            }
        }
        else{
            printf("Input number must be a number between 1 and 45!\n");
            i--;
        }
    }
}

int auto_selc(int ary[],int k) /*k for manual, originally auto k=0*/
{
    int i, j, num;
    for(i=k+1;i<=6;i++){
        num=(rand()%45)+1;
        for(j=1;j<i;j++){
            if(num==ary[j]){
                i--;
                break;
            }
        }
        if(i==j){
            ary[i]=num;
        }
    }
}

int semi_auto_selc(int ary[])
{
    int k; /*k for manual*/
    do{
        printf("How many numbers do you want to choose? (1~6) ");
        scanf("%d",&k);
    }while(!(k>=1&&k<=6));
    manual_selc(ary,k);
    auto_selc(ary,k);
}

int match_res(int ary[],int win_num[])
{
    int ctn=0;
        printf("The matched numbers :");
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                if(ary[i]==win_num[j]){
                    printf("%4d",win_num[j]);
                    ctn++;
                    break;
                }
            }

        }
        switch(ctn){
            case 6:
                printf("\n¢¡Congratulations! You won the first prize.\n\n");
                break;
            case 5:
                printf("\n¢¡Congratulations! You won the second prize.\n\n");
                break;
            case 4:
                printf("\n¢¡Congratulations! You won the third prize.\n\n");
                break;
            case 3:
                printf("\n¢¡Congratulations! You won the fourth prize.\n\n");
                break;
            default:
                printf("\n¢¡That's too bad. Please try again.\n\n");
                break;
        }
}

int main()
{
    int n_line, selc_way;
    char ans_draw;
    do{
        printf("\n======================================================\n");
        printf(" Hello! This is Market Minguinho Lottery!\n\n");
        printf(" How many lines to play? (Choose 1~5)\n");
        printf("======================================================\n");
        scanf("%d",&n_line);
    }while(!(n_line>=1&&n_line<=5));
    printf("\n=================== NOW YOUR LOTTO ===================\n");
    //need re-encoding.
    int num_list[5][7];
    srand(time(0));
    for(int n=0;n<n_line;n++){
        printf("\n======================================================\n");
        printf("%c line:: Which way do you want?\n\n",n+65);
        printf("1. Auto\n");
        printf("2. Semi-Auto\n");
        printf("3. Manual\n");
        printf("======================================================\n\n");
        scanf("%d",&selc_way);
        num_list[n][0]=selc_way;
        switch(selc_way){
            case 1:
                auto_selc(num_list[n],0);
                break;
            case 2:
                semi_auto_selc(num_list[n]);
                break;
            case 3:
                manual_selc(num_list[n],6);
                break;
            default:
                n--;
                break;
            }
        printf("\n=================== NOW YOUR LOTTO ===================\n");
        for(int i=0;i<=n;i++){
//            info_line(num_list[i],i);
            NEW_info_line(num_list,i);
        }
    }
    printf("======================================================\n");
    do{
        printf("Do you want to check out your lottery? ('y' or 'n') ");
        scanf(" %c",&ans_draw);
    }while(!(ans_draw=='y'||ans_draw=='n'));
    printf("\n");
    if(ans_draw=='y'){
        int win_num[1][7];
        auto_selc(win_num[0],0);
        printf("\n");
        printf("This week's Winning number is [ ");
        for(int i=1;i<=6;i++){
            printf("%4d",win_num[0][i]);
        }
        printf("   ] !\n\n");
        for(int n=0;n<n_line;n++){
            info_line(num_list[n],n);
            match_res(num_list[n],win_num[0]);
        }
        printf("Good bye~\n");
    }
    else{
        printf("Good luck~ Good bye~\n");
    }
    return 0;
}
