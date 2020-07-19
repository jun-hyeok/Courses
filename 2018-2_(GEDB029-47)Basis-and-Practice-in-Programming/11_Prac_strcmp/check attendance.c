#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    char id[100];
    char ans[10];
    FILE *fp = fopen("prac1.txt", "r");
    FILE *fp2 = fopen("attendance.txt", "w");
    fprintf(fp2, "studentid\tname\tattendance\n");

    int check=0;
    fgets(str,100,fp);
    while(fscanf(fp,"%s",str)!=EOF){
        if(check==0){
            check=1;
            strncpy(id, str, sizeof(str)-1);
        }else{
            check=0;
            printf("Is %s there?",str);
            scanf("%s",ans);
            if(!strcmp(ans,"yes")){
                fprintf(fp2,"%s\t%s\tO\n",id,str);
            }
            else{
                fprintf(fp2,"%s\t%s\tX\n",id,str);
            }}
        }
    fclose(fp);
    fclose(fp2);
}
