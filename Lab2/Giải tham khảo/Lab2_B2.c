#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int a=0,p=0,b=0;
    scanf("%d",&b);
    while(b>0)
    {
        a+=(b%10)*pow(2,p);
        p++;
        b/=10;
    }
    printf("%d",a);

    return 0;
}