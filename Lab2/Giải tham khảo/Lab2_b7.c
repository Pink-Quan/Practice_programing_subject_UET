#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void swap(float *a, float *b)
{
    float *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}
float RandomInRange(float a, float b, int seed)
{
    srand(seed);
    return a + (b - a) * rand() / RAND_MAX;
}
int main()
{
    float x=RandomInRange(-3,3,69),b=RandomInRange(0,1,96);
    float y=x+b;
    printf("y = %f\n",y);
    if(abs(y1-(int)y1)>=0.5f)
    {
        if(y>0)
            y=(int)y+1;
        else
            y=(int)y-1;
    }
    else
        y=(int)y;
    printf("y = %.7f",y);

    return 0;
}