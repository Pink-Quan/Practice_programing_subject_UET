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
    float a, b;
    scanf("%f%f", &a, &b);
    float rd = RandomInRange(a, b, 9993);
    printf("rd = %f", rd);

    float c1 = rd * 10;
    if (c1 - (int)c1 >= 0.5f)
        c1 += 1;
    printf("\nc1 = %.2f", ((int)c1) / 10.0f);

    float c2 = rd * 100;
    if (c2 - (int)c2 >= 0.5f)
        c2++;
    c2 = (int)c2;
    printf("\nc2 = %.3f", c2 / 100.0f);

    float c3 = rd / 1000000.0;
    int i = 0;
    while (abs(c3) > 1)
    {
        c3 *= 10;
        i++;
    }
    printf("\nc3 = %.2fe-%d", c2 / 100.0f, i);

    return 0;
}