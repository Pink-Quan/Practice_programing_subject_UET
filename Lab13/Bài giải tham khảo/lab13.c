#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "sophuc.h"

void Bai1()
{
    sophuc a,b;
    Nhap(&a);
    Xuat(a);
    Nhap(&b);
    Xuat(b);

    printf("Tong so phuc: ");
    Xuat(Tong(a,b));

    printf("Hieu so phuc: ");
    Xuat(Hieu(a,b));

    printf("Tich so phuc: ");
    Xuat(Tich(a,b));

    printf("Thuong so phuc: ");
    Xuat(Thuong(a,b));

    printf("Agrumen so phuc a: %.2f\n",Argument(a));
    printf("Agrumen so phuc b: %.2f\n",Argument(b));
    printf("Module so phuc a: %.2f\n",Module(a));
    printf("Module so phuc b: %.2f\n",Module(b));
}

void Bai2()
{
    FILE*f1;
    f1=fopen("Input1.txt","r");
    if(f1==NULL)
    {
        printf("Null file 1");
    }

    int m1[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            fscanf(f1,"%d",&m1[i][j]);
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",m1[i][j]);
        printf("\n");
    }
            
    fclose(f1);

    FILE*f2;
    f2=fopen("Input2.txt","r");
    if(f1==NULL)
    {
        printf("Null file 2");
    }
    
    int m,n;
    fscanf(f2,"%d",&m);
    fscanf(f2,"%d",&n);
    //printf("%d %d",m,n);
    int m2[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            fscanf(f2,"%d",&m2[i][j]);
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",m2[i][j]);
        printf("\n");
    }

    fclose(f2);
}

void Bai3()
{
    FILE*f1,*f2;
    f1=fopen("SinhVien.txt","r");
    f2=fopen("SinhVienCopy.txt","w");

    char t[1000];
    
    fread(t,1000,1,f1);
    //fscanf(f1,"%s[^\n]",t);
    
    printf("%s",t);
    fprintf(f2,"%s",t);

    fclose(f1);
    fclose(f2);
}

int main()
{
    //Bai1();    
    //Bai2();
    Bai3();

    return 0;
}
