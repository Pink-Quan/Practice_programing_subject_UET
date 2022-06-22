#include <stdio.h>
void Swap(int  *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int main()
{
    int a=5,b=4,c=7,d=2,e=1;
    
    if(a>b)
        Swap(&a,&b);
        
    if(c>d)
        Swap(&c,&d);
    if(a>c)
    {
        Swap(&b,&c);
        Swap(&a,&b);
    }
    else
    {
        Swap(&b,&c);
        Swap(&c,&d);
    }
    if(d>e)
        Swap(&d,&e);
        
    if(b>d)
    {
        Swap(&c,&d);
        Swap(&b,&c);
    }
    else
    {
        Swap(&c,&d);
        Swap(&d,&e);
    }
    if(c>e)
        Swap(&c,&e);
        
    printf("%d",c);
        
    return 0;
}
