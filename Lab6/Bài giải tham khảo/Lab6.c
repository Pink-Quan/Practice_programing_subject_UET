#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "CSupport.h"

void Bai1()
{
    int*bcc=(int*)malloc(sizeof(int)*30);
    for(int i=0,z=1;i<30;i+=3,z++)
    {
        bcc[i]=9;
        bcc[i+1]=z;
        bcc[i+2]=bcc[i]*bcc[i+1];
    }
    for(int i=0;i<30;i+=3)
    {
        printf("%d x %d = %d\n",bcc[i],bcc[i+1],bcc[i+2]);
    }
    
    printf("\nChange to bin\n");
    int*bccBin=(int*)malloc(sizeof(int)*30);;
    for(int i=0;i<30;i++)
    {
        bccBin[i]=(int)Dec2Bin(bcc[i]);
    }
    for(int i=0;i<30;i+=3)
    {
        printf("%08d x %08d = %08d\n",bccBin[i],bccBin[i+1],bccBin[i+2]);
    }
    
    int sizeOfData=30*8;
    int line1=32;
    int line2=64;
    int line3=16;
    printf("\nTime line 1: = %fs\n",(float)sizeOfData/(line1*1000));
    printf("Time line 2: = %fs\n",(float)sizeOfData/(line2*1000));
    printf("Time line 3: = %fs\n",(float)sizeOfData/(line3*1000));
    
    bccBin[0]=10001001;
    bccBin[29]=01011011;
    
    printf("\nError: \n");
    for(int i=0;i<30;i+=3)
    {
        printf("%d x %d = %d\n",Bin2Dec((long long)bccBin[i]),Bin2Dec((long long)bccBin[i+1]),Bin2Dec((long long)bccBin[i+2]));
    }
}
int BinarySearch(int*arr, int l, int r, int x) 
{
  if (r >= l) {
    int mid = l + (r - l) / 2;
 

    if (arr[mid] == x)
      return mid;
 

    if (arr[mid] > x)
      return BinarySearch(arr, l, mid - 1, x);
 

    return BinarySearch(arr, mid + 1, r, x);
  }
 

  return -1;
}
void Bai2()
{
    srand(669);
    int n=IntRandomFrom0ToN(9)+1;
    int**ma=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
        ma[i]=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ma[i][j]=IntRandomFrom0ToN(9);
            printf("%d ",ma[i][j]);
        }
        printf("\n");
    }
    printf("\nError\n");
    for(int i=0;i<n;i++)
        ma[i][i]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ma[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ma[i][j]);
        }
    }
    printf("\nArrange\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                for(int l=0;l<n;l++)
                {
                    if(ma[i][j]<ma[k][l])
                    {
                        int temp=ma[i][j];
                        ma[i][j]=ma[k][l];
                        ma[k][l]=temp;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ma[i][j]);
        }
        printf("\n");
    }
    
    int*ma1=(int*)malloc(sizeof(int)*n*n);
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ma1[c++]=ma[i][j];
        }
    }
    //for(int i=0;i<n*n;i++)
        //printf("%d ",ma1[i]);
    int s;
    printf("Binary Search: ");
    scanf("%d",&s);
    if(BinarySearch(ma1,n,n,s)==-1)
        printf("Not found\n");
    else
        printf("%d at %d\n",s,BinarySearch(ma1,n,n,s));
        
    printf("Time line 2 = %fs",(float)n*n*8/(64000));
}

int check(int i,int j,int p1,int p2)
{
    if((p2-p1)%2==1)
    {
        if(i-j==1)
            return 0;
        else 
        {
            return 1;
        }
        
    }
    else
    {
        if(i-j==2)
            return 0;
        else
            return 1;
    }
}

void Error1(char s[100])
{
   int p1=0,p2=0;
    while(s[p1]!=0)
    {
        while(s[p2]!=0&&s[p2]!=' ')
            p2++;
        p2++;
        printf("%d %d\n",p1,p2);
        for(int i=p1,j=p2-2;check(i,j,p1,p2-2);i++,j--)
        {
            char t=s[i];
            s[i]=s[j];
            s[j]=t;
        }
        p1=p2;
        
    }
    printf("%s\n",s);
}
void Error2(char s[100])
{
    int p1=strlen(s)-1,p2=p1;
    while(s[p2]!=0)
    {
        while (s[p1]!=' '&&s[p1]!=0)
        {
            p1--;
        }
        p1++;
        for(int i=p1;i<=p2;i++)
            printf("%c",s[i]);
        p1-=2;
        p2=p1;
        printf(" ");
    }
}
void Bai3()
{
    char data[100];
    printf("Input data: ");
    fgets(data,sizeof(data),stdin);
    data[strlen(data)-1]=(char)0;
    printf("Your data is: %s\n",data);

    int isSymmetry=1,len=strlen(data);
    printf("Your data len = %d\n",len);
    for(int i=0;i<len/2+1;i++)
        if(data[i]!=data[len-1-i])
        {
            isSymmetry=0;
            break;
        }
    if(isSymmetry)
        printf("Your text is Symmetry\n");
    else
        printf("Your text is not Symmetry\n");

    printf("Input char: ");
    char s,temp;
    scanf("%c%c",&s,&temp);
    int timeArr=0;
    for(int i=0;i<len;i++)
        if(s==data[i])
            timeArr++;
    if(timeArr)
        printf("Number of occurrences of the character = %d\n",timeArr);
    else
        printf("Your character not exis in text\n");

    Error1(data);
    Error2(data);
    printf("\nTime line 2 = %f",(float)len*sizeof(data[0])/(32000));
    
}

int main()
{
    //Bai1();
    //Bai2();
    Bai3();
}