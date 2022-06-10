#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int RandomInRange(int a, int b)
{
    srand(69996);
    return rand() % (b - a + 1);
}
void swap(float *a, float *b)
{
    float *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}
float Random(float n,int seed)
{
    srand(seed);
    return n*rand()/RAND_MAX;
}
int main()
{
    float a=Random(1,0),b=Random(1,1);
    if(a>b)
        swap(&a,&b);
    if(a>=0.5f) printf("a = 1\n"); else printf("a = 0\n");
    if(b>=0.5f) printf("b = 1\n"); else printf("b = 0\n");
    return 0;
}