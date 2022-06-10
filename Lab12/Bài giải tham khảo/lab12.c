#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include "CSupport.h"

typedef struct phanSo
{
    int tu;
    int mau;
}phanSo;

void NhapPhanSo(phanSo *ps)
{
    char tempString[100];
    printf("Input fraction: ");
    //getchar();
    fgets(tempString,sizeof(tempString),stdin);
    sscanf(tempString,"%d/%d",&ps->tu,&ps->mau);
}

void XuatPhanSo(phanSo ps)
{
    printf("%d / %d ",ps.tu,ps.mau);
}

int UCLN(int a,int b)
{
    a=abs(a);
    b=abs(b);
    int min=a;
    if(a>b)
        min=b;
    for(int i=b;i>=1;i--)
        if(a%i==0&b%i==0)
            return i;
    
    return -1;
}

void RutGonPhanSo(phanSo*ps)
{
    int rg=UCLN(ps->tu,ps->mau);
    ps->tu/=rg;
    ps->mau/=rg;
}

int BCNN(int a,int b)
{
    a=abs(a);
    b=abs(b);

    int max=a;
    if(a<b)
        max=b;
    for(int i=max;i<__INT_MAX__;i++)
        if(i%a==0&i%b==0)
            return i;
    return -1;
}

phanSo TongPhanSo(phanSo ps1,phanSo ps2)
{
    phanSo ps;
    ps.mau=ps1.mau*ps2.mau;
    ps.tu=ps1.tu*ps2.mau+ps2.tu*ps1.mau;

    int uc=UCLN(ps.tu,ps.mau);

    ps.tu/=uc;
    ps.mau/=uc;

    return ps;
}

phanSo HieuPhanSo(phanSo ps1,phanSo ps2)
{
    phanSo ps;
    ps.mau=ps1.mau*ps2.mau;
    ps.tu=ps1.tu*ps2.mau-ps2.tu*ps1.mau;

    int uc=UCLN(ps.tu,ps.mau);

    ps.tu/=uc;
    ps.mau/=uc;

    return ps;
}

phanSo TichPhanSo(phanSo ps1,phanSo ps2)
{
    phanSo ps;
    ps.mau=ps1.mau*ps2.mau;
    ps.tu=ps1.tu*ps2.tu;

    int uc=UCLN(ps.tu,ps.mau);

    ps.tu/=uc;
    ps.mau/=uc;

    return ps;
}

phanSo ThuongPhanSo(phanSo ps1,phanSo ps2)
{
    phanSo ps;
    ps.mau=ps1.mau*ps2.tu;
    ps.tu=ps1.tu*ps2.mau;

    int uc=UCLN(ps.tu,ps.mau);

    ps.tu/=uc;
    ps.mau/=uc;

    return ps;
}

void saveFractionData(phanSo data[],int len)
{
    FILE *f;
    f=fopen("Lap12_1.txt","a");
    for(int i=0;i<len;i++)
    {
        fprintf(f,"%d/%d ",data[i].tu,data[i].mau);
    }
    fclose(f);
}

void Ex1()
{
    phanSo ps1,ps2;
    NhapPhanSo(&ps1);
    NhapPhanSo(&ps2);
    RutGonPhanSo(&ps1);
    RutGonPhanSo(&ps2);
    XuatPhanSo(ps1);
    XuatPhanSo(ps2);

    phanSo ds[4]=
    {
        TongPhanSo(ps1,ps2),HieuPhanSo(ps1,ps2),TichPhanSo(ps1,ps2),ThuongPhanSo(ps1,ps2)
    };

    saveFractionData(ds,4);
}

typedef struct student
{
    char name[20];
    char birthDate[10];
    float mathScore;
    float englishScore;
    float itScore;
    float avgScore;
}student;

float AvgScore(student st)
{
    return st.mathScore+st.englishScore/2;
}

char*ProficiencyRating(student st)
{
    if(AvgScore(st)>=9.0)
        return "Excellent";
    else if (AvgScore(st)<9.0&&AvgScore(st)>=8.0)
    {
        return "Very_Good";
    }
    else if (AvgScore(st)<8.0&&AvgScore(st)>=6.5)
    {
        return "Good";
    }
    else if (AvgScore(st)<6.5&&AvgScore(st)>=5.0)
    {
        return "Average";
    }
    else if (AvgScore(st)<5.0)
    {
        return "Week";
    }

    return "NULL";
    
}

void InputStudent(student *a,int len)
{
    for(int i=0;i<len;i++)
    {
        char tempString[20];
        printf("Input student name: ");
        //getchar();
        fgets(a[i].name,sizeof(a[i].name),stdin);
        a[i].name[strlen(a[i].name)-1]=0;
        printf("Input student birth: ");
        //getchar();
        fgets(a[i].birthDate,sizeof(a[i].birthDate),stdin);
        a[i].name[strlen(a[i].birthDate)-1]=0;
        printf("Input Math score, English score and IT score: ");
        scanf("%f%f%f",&a[i].mathScore,&a[i].englishScore,&a[i].itScore);
        a[i].avgScore=(a[i].mathScore+a[i].englishScore)/2;
    }
}

void OutputStudent(student a[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf("\tStudent name: %s\t",a[i].name);
        printf("Student birth: %s\t",a[i].birthDate);
        printf("Math score and English score IT score: %.2f %.2f %.2f\t",a[i].mathScore,a[i].englishScore,a[i].itScore);
        printf("Average score: %.2f\n",a[i].avgScore);
    }
}

student SearchStudent(char name[],student a[],int len)
{
    student*null;
    for(int i=0;i<len;i++)
        if(strcmp(name,a[i].name))
            return a[i];

    return*null;
}

void SwapStudent(student *s1,student*s2);

void SordStudent(student*a,int len)
{
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++)
            if(a[i].itScore<a[j].itScore)
                SwapStudent(a[i],a[j]);
}

*student DeleteAtK(student a[],int len,int k)
{
    for(int i=k;i<len;i++)
        a[i]=a[i+1];
    return a;
}

void SwapStudent(student *s1,student*s2)
{
    student t=*s1;
    *s1=*s2;
    *s2=t;
}

int DeleteStudent(student a*, int len,char name[])
{
    int num=0;
    student searched=SearchStudent(name,a,len);
    for(int i=0;i<len;i++)
        if(searched==a[i])
        {
            a=DeleteAtK(a,len,i);
            num++;
        }
    return num;
}

void Ex2()
{
    student listStudent[10];
    InputStudent(listStudent,10);
    SordStudent(listStudent,10)
    OutputStudent(listStudent,10);
    char dl[20];
    printf("Delete student: ");
    fgets(dl,sizeof(dl),stdin);
    dl[strlen(dl)-1]=0;
    int dled=DeleteStudent(&listStudent,10,dl);
    OutputStudent(listStudent,10-dled);

    FILE *f;
    f=fopen("Lap12_2.txt","w");
    for(int i=0;i<10-dled;i++)
    {
        fprintf(f,"%s %s %f %f %f %f \n",listStudent[i].name,listStudent[i].birthDate,listStudent[i].mathScore,listStudent[i].englishScore,listStudent[i].itScore,listStudent[i].avgScore);
    }
    fclose(f);

}

int main()
{
    //Ex1();
    Ex2();

    return 0;
}