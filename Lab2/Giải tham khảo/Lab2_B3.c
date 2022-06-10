#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    printf("Random number using rand(): ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", rand());
    }
    printf("\nRandom number using srand: ");
    srand((int)(time(0)));
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", rand());
    }
    return 0;
}