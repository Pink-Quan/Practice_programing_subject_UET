#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int d,p=1,r;
    int b=0;
    scanf("%d",&d);
    while(d!=0)
    {
        r=d%2;
        d/=2;
        b+=r*p;
        p*=10;
    }
    printf("%d",b);

    return 0;
}