#include <stdio.h>
#include <stdlib.h>

void print_stars(int num)
{
    if(num==0){
        return 0;
    }
    else{
        print_stars(num-1);
        printf("\n");
        for(int i=0;i<num;i++){
            printf("*");
        }
    }

}
int main()
{
    print_stars(10);
    return 0;
}
