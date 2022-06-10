int IntRandomFrom0ToN(int N)
{
    return rand() % (N + 1);
}

int IntRandomFromAtoB(int A, int B)
{
    return A + rand() % (B - A + 1);
}

float FloatRandomFromAtoB(float A, float B)
{
    return A + (B - A) * rand() / RAND_MAX;
}

float FloatRandomFrom0toN(float n)
{
    return n * rand() / RAND_MAX;
}

void RandomFor1DimesionArray(int *array, int num)
{
    for (int i = 0; i < num; i++)
        array[i] = rand();
}

float RoundToNDecimalPlaces(float num, int n)
{
    return round(num * pow(10, n)) / pow(10, n);
}

long long ChangeToBit(int n)
{
    long long bin = 0;
    int rem, i = 1;

    while (n != 0)
    {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
}