#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "CSupport.h"

void Ex1()
{
    int n;
    printf("Input number of student: ");
    scanf("%d", &n);
    float *listItScoreStudent = (float *)malloc(sizeof(float) * n), maxScore, minScore;
    srand((int)time);
    for (int i = 0; i < n; i++)
    {
        listItScoreStudent[i] = FloatRandomFrom0toN(10.0);
        listItScoreStudent[i] = RoundToNDecimalPlaces(listItScoreStudent[i], 2);
    }
    maxScore = listItScoreStudent[0], minScore = maxScore;
    for (int i = 0; i < n; i++)
    {
        if (maxScore < listItScoreStudent[i])
            maxScore = listItScoreStudent[i];
        if (minScore > listItScoreStudent[i])
            minScore = listItScoreStudent[i];
    }

    printf("Max Score = %.2lf\n", maxScore);
    printf("Min Score = %.2lf\n", minScore);

    float sumScoreCPlus = 0;
    int numberOfAPlusStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (listItScoreStudent[i] >= 6.5 && listItScoreStudent[i] <= 6.9)
            sumScoreCPlus += listItScoreStudent[i];
        if (listItScoreStudent[i] >= 9)
            numberOfAPlusStudent++;
    }

    printf("Sum Score C+ score = %.2lf\nNumber of A+ score = %d", sumScoreCPlus, numberOfAPlusStudent);
}

void Ex2()
{
    int *rainfallInYear = (int *)malloc(sizeof(int) * 12), avgRainfallInYear = 0;
    srand((int)time);
    for (int i = 0; i < 12; i++)
    {
        rainfallInYear[i] = IntRandomFrom0ToN(500);
        avgRainfallInYear += rainfallInYear[i];
    }
    avgRainfallInYear /= 12;
    printf("Averange rainfall in year = %d\n", avgRainfallInYear);

    float o = 0;
    for (int i = 0; i < 12; i++)
    {
        o += (rainfallInYear[i] - avgRainfallInYear) * (rainfallInYear[i] - avgRainfallInYear) / 12;
    }
    o = sqrt(o);

    printf("Variance = %.2lf", o);
}

int *ChangeToArrayBit(int n)
{
    int *a = (int *)malloc(sizeof(int) * 8), *b = (int *)malloc(sizeof(int) * 8);
    for (int i = 0; i < 8; i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    for (int i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    for (int i = 0; i < 8; i++)
        b[i] = a[7 - i];
    return b;
}

void Ex3()
{
    int n;
    printf("Input smoothness of the graph: ");
    scanf("%d", &n);

    unsigned int *iList = (unsigned int *)malloc(sizeof(unsigned int) * n);
    float *list = (float *)malloc(sizeof(float) * n);

    srand(6969696);
    for (int i = 0; i < n; i++)
    {
        list[i] = FloatRandomFrom0toN(10);
        list[i] = round(list[i]);
        iList[i] = (int)list[i];
    }

    int **endcodeList = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        endcodeList[i] = (int *)malloc(8 * sizeof(int));
    }

    for (int i = 0; i < n; i++)
        endcodeList[i] = ChangeToArrayBit(iList[i]);

    int numBit1 = 0, numBit0 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 8; j++)
        {
            if (endcodeList[i][j])
                numBit1++;
            else
                numBit0++;
        }

    printf("Ratio of Number bit 1 / bit 0 = %.2lf\n", (float)numBit1 / numBit0);
    printf("Ratio of Number bit 1 / all bit = %.2lf\n", (float)numBit1 / (8 * n));

    int listBit1[numBit1], listBit0[numBit0];
    printf("List bit 1: ");
    for (int i = 0; i < numBit1; i++)
    {
        listBit1[i] = 1;
        printf("%d ", listBit1[i]);
    }
    printf("\n");

    printf("List bit 0: ");
    for (int i = 0; i < numBit0; i++)
    {
        listBit0[i] = 0;
        printf("%d ", listBit0[i]);
    }
    printf("\n");
}

void Ex4()
{
    int s;
    // printf("Input size of Image: ");
    // scanf("%d",&s);
    s=8;
    int **img1 = (int **)malloc(s * sizeof(int *));
    for (int i = 0; i < s; i++)
    {
        img1[i] = (int *)malloc(s * sizeof(int));
    }
    int **img2 = (int **)malloc(s * sizeof(int *));
    for (int i = 0; i < s; i++)
    {
        img2[i] = (int *)malloc(s * sizeof(int));
    }
    int **img3 = (int **)malloc(s * sizeof(int *));
    for (int i = 0; i < s; i++)
    {
        img3[i] = (int *)malloc(s * sizeof(int));
    }
    int **img4 = (int **)malloc(s * sizeof(int *));
    for (int i = 0; i < s; i++)
    {
        img4[i] = (int *)malloc(s * sizeof(int));
    }
    srand(6699);
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
        {
            img1[i][j] = IntRandomFrom0ToN(1);
        }
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
        {
            img2[i][j]=1;
            if(j>=i)
                img3[i][j]=1;
            else 
            {
                img3[i][j]=0;
            }
            
        }
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            img4[i][j] = 0;
            for (int k = 0; k < s; k++)
            {
                img4[i][j] ^= img1[i][k] * img2[k][j];
            }
        }
    }
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            img4[i][j]&=img3[i][j];

    printf("Matrix D:\n");
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
            printf("%d ",img4[i][j]);
        printf("\n");
    }
    printf("All Minor and Main diagonals line in matrix D: \n");
    for (int i = 0; i < s; i++)
    {
        for (int j = i, k=0; j < s&&k<s; k++,j++)
        {
                printf("%d ",img4[j][k]);
        }
        printf("\n");
    }
    for (int i = 1; i < s; i++)
    {
        for (int j = i, k=0; j < s&&k<s; k++,j++)
        {
                printf("%d ",img4[k][j]);
        }
        printf("\n");
    }
}

int IsSymmetricMatrix(int**a,int s)
{
    for(int i=0;i<s;i++)
        for(int j=0;j<s;j++)
            if(a[i][j]!=a[j][i])
                return 0;
    return 1;
}

void MatrixTransposition(int **a,int s)
{
    for(int i=0;i<s;i++)
        for(int j=0;j<i;j++)
        {
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }

}
void Ex5()
{
    int s;
    printf("Input size of square matrix: ");
    scanf("%d",&s);

    int**matrix=(int**)malloc(sizeof(int*)*s);
    for(int i=0;i<s;i++)
        matrix[i]=(int*)malloc(sizeof(int)*s);
    
    printf("Innput matrix:\n");
    for(int i=0;i<s;i++)
        for(int j=0;j<s;j++)
            scanf("%d",&matrix[i][j]);
    
    MatrixTransposition(matrix,s);
    printf("Matrix after transpose\n");
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
        
    if(IsSymmetricMatrix(matrix,s))
    {
        printf("Matrix is Symmetric\n");
    }
    else
    {
        printf("Matrix is not Symmetric\n");
    }
    printf("Sum of number in All Minor and Main diagonals line in matrix\n");
    for (int i = 0; i < s; i++)
    {
        int sum=0;
        for (int j = i, k=0; j < s&&k<s; k++,j++)
        {
            sum+=matrix[k][j];  
        }
        printf("%d ",sum);
    }
    for (int i = 1; i < s; i++)
    {
        int sum=0;
        for (int j = i, k=0; j < s&&k<s; k++,j++)
        {
            sum+=matrix[j][k];  
        }
        printf("%d ",sum);
    }
    
}

int main()
{
    // Ex1();
    // Ex2();
    // Ex3();
    // Ex4();
    // Ex5();

    return 0;
}