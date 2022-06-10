#include <stdio.h>
int GetLine(int line);
void Bai1()
{
    
    printf("Input line (1,2,3,4,5): ");
    int t, maxLine=GetLine(1), minLine=GetLine(1);
    scanf("%d", &t);
    printf("Line %d have cost = %d\n",t,GetLine(t));
    for(int i=1;i<=5;i++)
    {
        if(maxLine<GetLine(i))
            maxLine=GetLine(i);
        if(minLine>GetLine(i))
            minLine=GetLine(i);
    }
    printf("Max line = %d, Min line = %d",maxLine,minLine);
}
int GetCost(int p[2])
{
    return p[0] * 2 + p[1];
}

int GetLine(int line)
{
    int ab[2] = {4, 3}, bc[2] = {2, 5}, cd[2] = {3, 6}, ae[2] = {5, 2}, ef[2] = {3, 3}, fd[2] = {1, 4}, ad[2] = {4, 7}, ed[2] = {2, 6}, bd[2] = {3, 7};
    switch (line)
    {
    case 1:
        return GetCost(ab)+GetCost(bc)+GetCost(cd);
    case 2:
        return GetCost(ab)+GetCost(bd);
    case 3:
        return GetCost(ad);
    case 4:
        return GetCost(ae)+GetCost(ed);
    case 5:
        return GetCost(ae)+GetCost(ef)+GetCost(fd);
    default:
        return -1;
    }
    return -1;
}

void Bai2()
{
    int minLine=GetLine(1),maxLine=GetLine(1);
    for(int i=1;i<=3;i++)
    {
        int line=i*2-1;
        if(maxLine<GetLine(line))
            maxLine=GetLine(line);
        if(minLine>GetLine(line))
            minLine=GetLine(line);
    }
    int l;
    printf("Input line (1,2,3): "); //Same with line 1,3,5 as Ex1
    scanf("%d",&l);
    if(l==1||l==2||l==3)
    {
        l=l*2-1;
        if(GetLine(l)==minLine)
        {
            int sumCost=0;
            for(int i=0;i<20;i++)
                sumCost+=GetLine(l);
            printf("Sum cost = %d",sumCost);
        }
        else if(GetLine(l)==maxLine)
        {
            int sumCost=0;
            int count=1;
            while(count<11)
            {
                sumCost+=GetLine(l);
                count++;
            }
            printf("Sum cost = %d",sumCost);
        }
        else
        {
            printf("Max line > Your line > Min Line");
        }
        
    }
    else
    {
        printf("Invalid line");
    }
    
}

int GetDelay(int line) //For ex3
{
    int ab[2] = {4, 3}, bc[2] = {2, 5}, cd[2] = {3, 6}, ae[2] = {5, 2}, ef[2] = {3, 3}, fd[2] = {1, 4}, ad[2] = {4, 7}, ed[2] = {2, 6}, bd[2] = {3, 7};
    switch (line)
    {
    case 1:
        return ab[1]+bc[1]+cd[1];
    case 2:
        return ad[1];
    case 3:
        return ae[1]+ef[1]+fd[1];
    default:
        return -1;
    }
    return -1;
}

void Bai3()
{
    for(int i=1;i<=3;i++)
    {
        printf("With line %d, delay = %d if Flag = 1 and delay = %d if Flag = 0\n",i,GetDelay(i),GetDelay(i)*2);
    }
}

void Bai4()
{
    printf("San pham tot\tSan pham hong\n");
    int ratio=10,sp=1;
    while(sp!=101)
    {
        printf("\t%d\n",sp);
        sp++;
        if(ratio!=0)
        {
            printf("\t\t%d\n",sp);
            ratio--;
            sp++;
            continue;
        }
    }
}

void Bai5()
{
    printf("Cho hinh chu nhat co chieu dai gap hai lan chieu rong va chu vi bang dien tich, viet chuong trinh tinh chieu dai, chieu rong va dien tich cua hinh chu nhat, va in ket qua ra man hinh");
    int i=1;
    while(1)
    {
        if(i*2*i==2*(i+2*i))
            break;
        i++;
    }
    printf("\n\nWith and length of retangular = (%d,%d)\nArea = %d",i,i*2,i*i*2);
}

int main()
{
    //Bai1();
    //Bai2();
    //Bai3();
    //Bai4();
    Bai5();
    return 0;
}