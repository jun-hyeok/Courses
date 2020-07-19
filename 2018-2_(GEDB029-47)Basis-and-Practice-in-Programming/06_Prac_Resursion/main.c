#include <stdio.h>
#include <stdlib.h>

void print_stars(int num)
{
    if(num==0){
        return 0;
    }
    else{
        for(int i=0;i<num;i++){
            printf("*");
        }
        printf("\n");
        print_stars(num-1);
    }

}
int main()
{
    print_stars(10);
    return 0;
}
