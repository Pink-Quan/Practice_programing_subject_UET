#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "CSupport.h"

void Ex1()
{
    float a, b;
    int sizeA, sizeB;
    printf("Input range a,b: ");
    scanf("%f%f", &a, &b);
    printf("Input size of matrix A,B: ");
    scanf("%d%d", &sizeA, &sizeB);

    float *matrixA = (float *)malloc(sizeof(float) * sizeA);
    float *matrixB = (float *)malloc(sizeof(float) * sizeB);

    printf("Generate randomly prossessing...\n");
    srand(a + b + sizeA + sizeB);
    for (int i = 0; i < sizeA; i++)
        matrixA[i] = FloatRandomFromAtoB(a, b);
    for (int i = 0; i < sizeB; i++)
        matrixB[i] = FloatRandomFromAtoB(a, b);

    printf("Arrange matrix prossessing...\n");
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = i + 1; j < sizeA; j++)
        {
            if (matrixA[i] > matrixA[j])
            {
                float temp = matrixA[i];
                matrixA[i] = matrixA[j];
                matrixA[j] = temp;
            }
        }
    }
    for (int i = 0; i < sizeB; i++)
    {
        for (int j = i + 1; j < sizeB; j++)
        {
            if (matrixB[i] > matrixB[j])
            {
                float temp = matrixB[i];
                matrixB[i] = matrixB[j];
                matrixB[j] = temp;
            }
        }
    }

    printf("Merge and fusion matrix prossessing...\n");
    int sizeC = sizeA + sizeB, odd = 0, even = 0;
    float *matrixC = (float *)malloc(sizeof(float) * sizeB);
    for (int i = 0; i < sizeA; i++)
        matrixC[i] = matrixA[i];
    for (int i = 0; i < sizeB; i++)
        matrixC[i + sizeA] = matrixB[i];
    for (int i = 0; i < sizeC; i++)
    {
        for (int j = i + 1; j < sizeC; j++)
        {
            if (matrixC[i] > matrixC[j])
            {
                float temp = matrixC[i];
                matrixC[i] = matrixC[j];
                matrixC[j] = temp;
            }
        }
    }
    for (int i = 0; i < sizeC; i++)
    {
        if ((int)matrixC[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    int *matrixD = (int *)malloc(sizeof(int) * even);
    int *matrixE = (int *)malloc(sizeof(int) * odd);

    for (int i = 0, o = 0, e = 0; i < sizeC; i++)
    {
        if ((int)matrixC[i] % 2 == 0)
        {
            matrixD[e] = (int)matrixC[i];
            e++;
        }
        else
        {
            matrixE[o] = (int)matrixC[i];
            o++;
        }
    }
    printf("Matrix C= ");
    for (int i = 0; i < sizeC; i++)
        printf("%f ", matrixC[i]);
    printf("\nMatrix D= ");
    for (int i = 0; i < even; i++)
        printf("%d ", matrixD[i]);
    printf("\nMatrix E= ");
    for (int i = 0; i < odd; i++)
        printf("%d ", matrixE[i]);
}

void Ex2()
{
    int m, n;
    printf("Input size matrix A, m x n: ");
    scanf("%d%d", &m, &n);
    int **matrix = (int **)malloc(m * sizeof(int *));
    int **matrixB = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        matrixB[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Generate randomly prossessing...\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = IntRandomFrom0ToN(9);
    
    printf("Matrix A: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }

    printf("Matrix B prossessing...\n");
    int SumCollumA[n];
    for(int i=0;i<n;i++)
        SumCollumA[i]=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            SumCollumA[i] += matrix[j][i];

    printf("Sum collum matrix A: ");
    for (int i = 0; i < n; i++)
        printf("%d ",SumCollumA[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int k = 0; k <= i; k++)
                sum += SumCollumA[k];
            matrixB[j][i] = sum;
        }
    }
    printf("MatrixB\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    int maxValueOfB = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (maxValueOfB < matrixB[i][j])
                maxValueOfB = matrixB[i][j];
    }
    printf("Max value of matrix B= %d\n", maxValueOfB);
    printf("Matrix C prossessing... \n");

    int **matrixC = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrixC[i] = (int *)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            matrixC[i][j] = matrixB[j][i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int l = 0; l < n; l++)
            {
                for (int k = 0; k < m; k++)
                {
                    if(matrixC[i][j]<matrixC[l][k])
                    {
                        int temp=matrixC[i][j];
                        matrixC[i][j]=matrixC[l][k];
                        matrixC[l][k]=temp;
                    }
                }
            }
        }
    }
    printf("Matrix C: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ",matrixC[i][j]);
        printf("\n");
    }
}

void Ex3()
{
    printf("Input string: ");
    char s[200];
    fgets(s,sizeof(s),stdin);
    s[strlen(s)-1]=(char)0;
    int i=0;
    while(s[0]==' ') //Delate head
    {
        for(int i=0;i<strlen(s)-1;i++)
            s[i]=s[i+1];
    }
    while(s[strlen(s)-1]==' ') //Delate tail
        s[strlen(s)-1]=(char)0;

    while(i!=strlen(s)-1)
    {
        if(s[i]==' '&&s[i+1]==' ')
        {
            for(int k=i;k<=strlen(s);k++)
                s[k]=s[k+1];
            i--;
        }
        i++;
    }
    int words=1;
    for(int i=0;i<strlen(s);i++)
        if(s[i]==' ')
            words++;
    printf("String after prossess: %s\n",s);
    printf("Number of words= %d\n",words);
    if(s[0]<='z'&&s[0]>='a')
        s[0]-=32;
    for(int i=0;i<strlen(s);i++)
        if(s[i]==' '&&s[i+1]<='z'&&s[i+1]>='a')
            s[i+1]-=32;
    printf("String after prossess x2: %s\n",s);
    char t[]="Toi yeu UET";
    strcat(s,t);
    printf("String after prossess x3: %s\n",s);
}

int main()
{
    srand(89);
    // Ex1();
     Ex2();
    //Ex3();
}