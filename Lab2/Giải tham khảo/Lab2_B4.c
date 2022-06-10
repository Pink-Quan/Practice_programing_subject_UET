#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int RandomInRange(int a,int b)
{
    srand((int)time(0));
    return rand()%(b-a+1);
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Random number in range: ");
        printf("%d ",RandomInRange(a,b));

    return 0;
}