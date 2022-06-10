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

long long Dec2Bin(int decimalNumber)
{
    long long binaryNumber = 0;
    int p = 0;
    while (decimalNumber > 0)
    {
        binaryNumber += (decimalNumber % 2) * pow(10, p);
        ++p;
        decimalNumber /= 2;
    }
    return binaryNumber;
}

int Bin2Dec(long long binaryNumber)
{
    int p = 0;
    int decNumber = 0;
    while (binaryNumber > 0)
    {
        decNumber += (binaryNumber % 10) * pow(2, p);
        ++p;
        binaryNumber /= 10;
    }
    return decNumber;
}