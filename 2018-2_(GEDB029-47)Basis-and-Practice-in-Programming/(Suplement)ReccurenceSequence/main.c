#include <stdio.h>
#include <stdlib.h>

#define _liimit_ 9

int greatCommon()
{

}
int finite(int* nu, int* de)
{

}
void infinite(int nu, int de)
{
    int i, j;
    int common, temp, infi;
    int nine=9;
    int stop ten=1;
    for(i=0;i<_limit_;i++){
        if(nine%de==0)
            break;
        temp=nine;
        for (j=i;j<_liimit_;j++){
            nine*=10;
            ten*=10;
            if(nine%de==0)
                stop=1;
                break;
        }
        if(stop==1)
            break;

        ten=1;
        nine=temp*10+9;
    }
    common=nine/de;
    nu=nu*common;
    if(ten==1){
            printf("0.[%d]\n\n",nu);
    }
    else{
        infi=nu/(nine/ten);
        nu=nu%(nine/ten);
        printf("0.%d[%d]",iffi,nu);
    }

int main()
{
    int nu, de;
    printf("Input number:");
    scanf("%d",&nu);
    printf("Input denominator:");
    scanf("%d",&de);

    return 0;
}
