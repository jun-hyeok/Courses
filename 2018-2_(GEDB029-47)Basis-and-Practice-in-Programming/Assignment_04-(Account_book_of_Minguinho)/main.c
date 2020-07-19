#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void opt_1()
{
    char str[100];
    FILE *fp = fopen("account_book_with_error.txt", "r");

    while(fgets(str,sizeof(str),fp)!=0)
        printf("%s",str);
    fclose(fp);
    printf("\n");
}
void opt_2()
{
    char str[100];
    float num_p=0, num_c=0, num_b=0, num_j=0;
    float prf_p=0, prf_c=0, prf_b=0, prf_j=0;
    FILE *fp = fopen("account_book_no_error.txt", "r");

    while(fscanf(fp,"%s",str)!=EOF){
        if(!strcmp("pen",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            num_p+=atoi(str);
            fscanf(fp,"%s",str);
            prf_p+=atoi(str);
        }else if(!strcmp("coffee",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            num_c+=atoi(str);
            fscanf(fp,"%s",str);
            prf_c+=atoi(str);
        }else if(!strcmp("bread",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            num_b+=atoi(str);
            fscanf(fp,"%s",str);
            prf_b+=atoi(str);
        }else if(!strcmp("juice",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            num_j+=atoi(str);
            fscanf(fp,"%s",str);
            prf_j+=atoi(str);
        }
    }
    printf(">> settlement\n");
    printf("pen\t%d\t%d\n",(int)num_p,(int)prf_p);
    printf("coffee\t%d\t%d\n",(int)num_c,(int)prf_c);
    printf("bread\t%d\t%d\n",(int)num_b,(int)prf_b);
    printf("juice\t%d\t%d\n",(int)num_j,(int)prf_j);
    printf("total profit :%d\n",(int)(prf_p+prf_c+prf_b+prf_j));
    printf("Settlement finished!\n\n");
}
void opt_3()
{
    char str[100];
    float num_p=0, num_c=0, num_b=0, num_j=0;
    FILE *fp = fopen("account_book_with_error.txt", "r");

    while(fscanf(fp,"%s",str)!=EOF){
        if(!strcmp("pen",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            num_p+=atoi(str);
        }else if(!strcmp("coffee",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            num_c+=atoi(str);
        }else if(!strcmp("bread",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            num_b+=atoi(str);
        }else if(!strcmp("juice",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            num_j+=atoi(str);
        }
    }
    int prf_p=num_p*800, prf_c=num_c*1500, prf_b=num_b*2000, prf_j=num_j*1300;
    printf(">> settlement\n");
    printf("pen\t%d\t%d\n",(int)num_p,prf_p);
    printf("coffee\t%d\t%d\n",(int)num_c,prf_c);
    printf("bread\t%d\t%d\n",(int)num_b,prf_b);
    printf("juice\t%d\t%d\n",(int)num_j,prf_j);
    printf("total profit :%d\n",prf_p+prf_c+prf_b+prf_j);
    printf("Settlement finished!\n\n");
}
void opt_4()
{
    char str[100], prd[100];
    float num_p=0, num_c=0, num_b=0, num_j=0;
    FILE *fp = fopen("account_book_with_error.txt", "r");
    FILE *fp_m = fopen("account_book_modified.txt", "w");

    while(fscanf(fp,"%s",str)!=EOF){
        if(!strcmp("pen",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            fprintf(fp_m,"pen\t%d\t%s\t%d\n",800,str,(int)(atoi(str)*800));
            num_p+=atoi(str);
        }else if(!strcmp("coffee",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            fprintf(fp_m,"coffee\t%d\t%s\t%d\n",1500,str,(int)(atoi(str)*1500));
            num_c+=atoi(str);
        }else if(!strcmp("bread",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            fprintf(fp_m,"bread\t%d\t%s\t%d\n",2000,str,(int)(atoi(str)*2000));
            num_b+=atoi(str);
        }else if(!strcmp("juice",str)){
            fscanf(fp,"%s",str);
            fscanf(fp,"%s",str);
            fprintf(fp_m,"juice\t%d\t%s\t%d\n",1300,str,(int)(atoi(str)*1300));
            num_j+=atoi(str);
        }
    }
    fclose(fp);
    fclose(fp_m);

    int prf_p=num_p*800, prf_c=num_c*1500, prf_b=num_b*2000, prf_j=num_j*1300;
    printf(">> settlement\n");
    printf("pen\t%d\t%d\n",(int)num_p,prf_p);
    printf("coffee\t%d\t%d\n",(int)num_c,prf_c);
    printf("bread\t%d\t%d\n",(int)num_b,prf_b);
    printf("juice\t%d\t%d\n",(int)num_j,prf_j);
    printf("total profit :%d\n",prf_p+prf_c+prf_b+prf_j);
    printf("Settlement finished!\n\n");
}
int main()
{
    int opt, term=1;
    while(term){
        printf("=============================================================================\n");
        printf("Minguinho Market Account Program\n");
        printf("Select menu!\n");
        printf("1. Settle this Account Book file\n");
        printf("2. Calculation the revenue for Normal Document\n");
        printf("3. Calculation the revenue for Error Document including invalid sales lists\n");
        printf("4. Making new sales document for Error Document including invalid sales lists\n");
        printf("5. Exit\n");
        printf("=============================================================================\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                opt_1();
                break;
            case 2:
                opt_2();
                break;
            case 3:
                opt_3();
                break;
            case 4:
                opt_4();
                break;
            case 5:
                term=0;
                printf("Exit the program.\n");
                break;
            default:
                printf("Select a number from 1 to 5\n");
                break;
        }
    }
    return 0;
}
