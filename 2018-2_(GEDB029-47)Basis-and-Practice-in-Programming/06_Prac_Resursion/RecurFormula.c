#include <stdio.h>
#include <stdlib.h>

int sequence(int n)
{
    if(n==1){
        return 2;
    }
    if(n==2){
        return 3;
    }
    return sequence(n-1)-2*sequence(n-2)+5;

}
int main()
{
    int n;
    printf("Input number : ");
    scanf("%d",&n);
    printf("The result of A%d is %d.",n,sequence(n));
    return 0;
}
