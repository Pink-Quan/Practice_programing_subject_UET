#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "CSupport.h"

void Ex1()
{
    srand(89);
    int m = IntRandomFrom0ToN(100), n = IntRandomFrom0ToN(100);
    printf("Size of matrix: %d x %d\n", m, n);
    int matrix[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            matrix[i][j]=IntRandomFrom0ToN(255);
    }
    printf("Radom matrix:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
           printf("%d ",matrix[i][j]);
        printf("\n");
    }

    printf("Derivative in the right direction\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==m-1)
            {
                if(matrix[i][j]>100)
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                int x=matrix[i][j+1]-matrix[i][j];
                if(x>100)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("Derivative in the left direction\n");
    for(int i=0;i<m;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(j==0)
            {
                if(matrix[i][j]>100)
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                int x=matrix[i][j-1]-matrix[i][j];
                if(x>100)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("Derivative in the down direction\n");
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            if(i==m-1)
            {
                if(matrix[i][j]>100)
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                int x=matrix[i+1][j]-matrix[i][j];
                if(x>100)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("Derivative in the up direction\n");
    for(int j=0;j<n;j++)
    {
        for(int i=m-1;i>=0;i--)
        {
            if(i==0)
            {
                if(matrix[i][j]>100)
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                int x=matrix[i-1][j]-matrix[i][j];
                if(x>100)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}

void Ex2()
{
    srand(6969);
    int len=IntRandomFrom0ToN(200);
    int arr[len];
    printf("Length of Array = %d\nArray = ",len);
    for(int i=0;i<len;i++)
    {
        arr[i]=IntRandomFromAtoB(-500,500);
        printf("%d ",arr[i]);
    }

    printf("\nLocal minium Array = ",len);
    for(int i=0;i<len;i++)
    {
        int right=i+20,left=i-20;
        if(right>len&&left<0)
        {
            right=len;
            left=0;
        }
        else if (right>len&&left>0)
        {
            if(left-(20-(len-i))>0)
                left-=(20-(right-len));
            else
                left=0;
            right=len;
        }
        else if (right<=len&&left<0)
        {
            if(right+(20-i)>0)
                right+=(20-i);
            else
                right=len;
            right=len;
        }
        
        int noiseCount=0;
        int isValid=1;
        for(int j=i;j<right-1;j++)
        {
            if(arr[j]<arr[j+1])
                continue;
            else if (arr[j]>arr[j+1])
            {
                if(arr[j+1]<arr[j+2])
                {
                    noiseCount++;
                    if(noiseCount==4)
                    {
                        isValid=0;
                        break;
                    }
                }
                else
                {
                    isValid=0;
                    break;
                }
            }
            
        }
        
        if(isValid==0)
            continue;
        
        noiseCount=0;
        isValid=1;
        for(int j=i;j>=left;j--)
        {
            if(arr[j]<arr[j-1])
                continue;
            else
            {
                if(arr[j-1]>arr[j-2])
                {
                    noiseCount++;
                    if(noiseCount==4)
                    {
                        isValid=0;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        if(isValid)
        printf("%d ",arr[i]);

    }

}

void Ex3()
{
    int a[6][5]=
    {
        5,7,7,7,5,
        6,8,3,8,10,
        10,0,1,5,0,
        5,3,1,4,4,
        4,4,6,8,5,
        9,9,9,3,7
    };

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<5;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    int sum[6];
    for(int i=0;i<6;i++)
    {
        sum[i]=0;
        for(int j=0;j<5;j++)
        {
            sum[i]+=a[i][j];
        }
    }

    int nearest=abs(sum[4]-sum[0]);
    for(int i=1;i<6;i++)
    {
        if(i!=4)
        {   
            int dis=abs(sum[4]-sum[i]);
            if(dis<nearest)
                nearest=dis;
        }
    }
    printf("Nearest meaning with E is: ");
    for(int i=0;i<6;i++)
    {
        int dis=abs(sum[4]-sum[i]);
        if(dis==nearest)
            printf("%c ",i+65);
    }
    printf("\n");

    int cutest=0,pupular=0,cutestTemp=a[0][4],pupularTemp=a[0][3];
    for(int i=0;i<6;i++)
    {
        if(a[i][4]>cutestTemp)
        {
            cutestTemp=a[i][4];
            cutest=i;
        }
        if(a[i][3]>pupularTemp)
        {
            pupularTemp=a[i][3];
            pupular=i;
        }
    }
    printf("Cutest word is %c and most popular word is %c\n",cutest+65,pupular+65);

    int love=0,positive=0,loveTemp=a[0][1],positiveTemp=a[0][2];
    for(int i=0;i<6;i++)
    {
        if(a[i][1]>loveTemp)
        {
            loveTemp=a[i][1];
            love=i;
        }
        if(a[i][2]>positiveTemp)
        {
            positiveTemp=a[i][2];
            positive=i;
        }
    }
    printf("Lovest word is %c and most positive word is %c\n",love+65,positive+65);

    int slove=0,spositive=0,sloveTemp=0,spositiveTemp=0;
    for(int i=0;i<6;i++)
    {
        if(a[i][1]>sloveTemp&&i!=love)
        {
            sloveTemp=a[i][1];
            slove=i;
        }
        if(a[i][2]>spositiveTemp&&i!=positive)
        {
            spositiveTemp=a[i][2];
            spositive=i;
        }
    }
    printf("Second Lovest word is %c and most positive word is %c\n",slove+65,spositive+65);
    
    int nearst=100;
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            int dis=abs(sum[i]-sum[j]);
            if(dis<nearest)
                nearest=dis;
        }
            
    }
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            int dis=abs(sum[i]-sum[j]);
            if(dis==nearest)
            {
                printf("\nNeareat word is %c and %c",i+65,j+65);
                break;
            }
        }
            
    }
}

int main()
{
    //Ex1();
    //Ex2();
    Ex3();
}