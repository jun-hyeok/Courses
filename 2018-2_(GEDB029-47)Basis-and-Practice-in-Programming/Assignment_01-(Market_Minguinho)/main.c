#include <stdio.h>

int main()
{
    int budget, selc_menu, selc_item, quant_num, tot_pric, tot_cost=0;
    do
    {
        printf("How much money do you have?(KRW):");
        scanf("%d",&budget);
    }while(budget<0);

    printf("\n================================\n");
    printf("Hello! This is market Minguinho!");
    while(1)
    {
        printf("\n==============MENU==============\n");
        printf("1. Buy items\n");
        printf("2. Finish and pay\n");
        printf("================================\n");
        printf("Select the menu which you want.(1 or 2):");
        scanf("%d",&selc_menu);
        if(selc_menu==1)
        {

            printf("\n================================\n");
            printf("You have %d KRW.\n",budget);
            printf("Choose anything you want!(1~5)\n");
            printf("1. Pen:\t\t  800KRW\n");
            printf("2. Notebook:\t 1500KRW\n");
            printf("3. Sandwiches:\t 2000KRW\n");
            printf("4. Juice:\t 1300KRW\n");
            printf("5. Candy:\t  300KRW(during the event of 'buy 2 get 1 free')\n");
            printf("================================\n");
            printf("Select item you want.(1~5):");
            scanf("%d",&selc_item);

            switch(selc_item)
            {
                case 1:
                    printf("How many do you want?:");
                    scanf("%d",&quant_num);
                    tot_pric=800*quant_num;
                    break;
                case 2:
                    printf("How many do you want?:");
                    scanf("%d",&quant_num);
                    tot_pric=1500*quant_num;
                    break;
                case 3:
                    printf("How many do you want?:");
                    scanf("%d",&quant_num);
                    tot_pric=2000*quant_num;
                    break;
                case 4:
                    printf("How many do you want?:");
                    scanf("%d",&quant_num);
                    tot_pric=1300*quant_num;
                    break;
                case 5:
                    printf("How many do you want?:");
                    scanf("%d",&quant_num);
                    tot_pric=300*(quant_num*2/3+quant_num%3);
                    break;
                default:
                    printf("Choose a number from 1 to 5, please~\n");
                    continue;
            }
            if (budget<tot_pric)
            {
                printf("You don't have enough budget.(return to menu)\n");
                continue;
            }
            else
            {
                budget-=tot_pric;
                tot_cost+=tot_pric;
                printf("\nPrice of selected items: %dKRW\n",tot_pric);
                printf("Total money you need to pay: %dKRW\n",tot_cost);
                printf("Your budget is %dKRW, now\n",budget);
                continue;
            }

        }
        else if(selc_menu==2)
        {
            printf("\nYou have %dKRW, now\n",budget);
            printf("Good bye~ Have a nice day~\n");
            break;
        }
        else
        {
            printf("Input 1 or 2!\n");
            continue;
        }
    }

    return 0;
}
