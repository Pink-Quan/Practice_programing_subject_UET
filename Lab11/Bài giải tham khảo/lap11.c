#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include "CSupport.h"

void Ex1()
{
    typedef struct student
    {
        int id;
        char name[20];
        int age;
        float scoreTest;

    } student;
    int studentCount;
    printf("Input number of student: ");
    scanf("%d", &studentCount);

    float hightestScore = 0, sumScore = 0, longestName = 0;

    student *studentList = (student *)malloc(sizeof(student) * studentCount);
    for (int i = 0; i < studentCount; i++)
    {
        printf("Input id of number %d of student: ", i);
        scanf("%d", &studentList[i].id);
        printf("Input name of number %d of student: ", i);
        getchar();
        fgets(studentList[i].name, sizeof(studentList[i].name), stdin);
        printf("Input age of number %d of student: ", i);
        scanf("%d", &studentList[i].age);
        printf("Input score of number %d of student: ", i);
        scanf("%f", &studentList[i].scoreTest);

        if (hightestScore < studentList[i].scoreTest)
            hightestScore = studentList[i].scoreTest;

        sumScore += studentList[i].scoreTest;

        if (strlen(studentList[i].name) > longestName)
            longestName = strlen(studentList[i].name);
    }

    printf("The student have hightest score: ");
    for (int i = 0; i < studentCount; i++)
    {
        if (studentList[i].scoreTest == hightestScore)
            printf("%s   ", studentList[i].name);
    }
    printf("\n");

    printf("The student have longest full name: ");
    for (int i = 0; i < studentCount; i++)
    {
        if (strlen(studentList[i].name) == longestName)
            printf("%s   ", studentList[i].name);
    }
    printf("\n");

    printf("Aventage score of all student = %f", (float)sumScore / studentCount);
}

void Ex2()
{
    typedef struct nationInfor
    {
        
        char name[20];
        float incomePerCapia;
        int population;
        int covid19;

    }nationInfor;

    int nationCount;
    printf("Input number of nation: ");
    scanf("%d", &nationCount);

    float hightestCovidRatio = 0, lowestIPC=__INT_MAX__;

    nationInfor *nationList = (nationInfor *)malloc(sizeof(nationInfor) * nationCount);
    for(int i=0;i<nationCount;i++)
    {
        printf("Enter nation name: ");
        getchar();
        fgets(nationList[i].name,sizeof(nationList[i].name),stdin);
        nationList[i].name[strlen(nationList[i].name)-1]=0;
        printf("Enter income per capia of %s: ",nationList[i].name);
        scanf("%f",&nationList[i].incomePerCapia);
        printf("Enter population of %s: ",nationList[i].name);
        scanf("%d",&nationList[i].population);
        printf("Enter number person having covid 19 of %s: ",&nationList[i].name);
        scanf("%d",&nationList[i].covid19);

        float ratio=(float)nationList[i].covid19/(float)nationList[i].population;
        if(ratio>hightestCovidRatio)
            hightestCovidRatio=ratio;

        if(lowestIPC>nationList[i].incomePerCapia)
            lowestIPC=nationList[i].incomePerCapia;
    }

    printf("The country with the highest rate of covid-19: ");
    for(int i=0;i<nationCount;i++)
    {
        if(hightestCovidRatio==(float)nationList[i].covid19/(float)nationList[i].population)
            printf("%s   ",nationList[i].name);
    }
    printf("\n");

    printf("The country with the lowest income per capia: ");
    for(int i=0;i<nationCount;i++)
    {
        if(lowestIPC==nationList[i].incomePerCapia)
            printf("%s   ",nationList[i].name);
    }
    printf("\n");
    
}

int TurnOffK(int n, int k)
{
    if (k <= 0) return n;
 
    return (n & ~(1 << (k - 1)));
}

int TurnOnK(int n, int k)
{

    if (k <= 0)
        return n;

    return (n | (1 << (k - 1)));
}

int Dec2Bin(int decimalNumber)
{
    int binaryNumber = 0;
    int p = 0;
    while (decimalNumber > 0)
    {
        binaryNumber += (decimalNumber % 2) * pow(10, p);
        ++p;
        decimalNumber /= 2;
    }
    return binaryNumber;
}

void Ex3()
{
    typedef struct IPData
    {
        
        short other;
        short fileLenSum;
        int sourceAddress[4];
        int destinationAddress[4];
        char data[100];

    }IPData;

    int line[4]={0,32,64,16};

    IPData PC1;
    printf("Input other value: ");
    scanf("%d",&PC1.other);
    char tempString[100];
    printf("Input source address: ");
    getchar();
    fgets(tempString,sizeof(tempString),stdin);
    sscanf(tempString,"%d.%d.%d.%d",&PC1.sourceAddress[0],&PC1.sourceAddress[1],&PC1.sourceAddress[2],&PC1.sourceAddress[3]);
    printf("Input destination address: ");
    getchar();
    fgets(tempString,sizeof(tempString),stdin);
    sscanf(tempString,"%d.%d.%d.%d",&PC1.destinationAddress[0],&PC1.destinationAddress[1],&PC1.destinationAddress[2],&PC1.destinationAddress[3]);
    printf("Input data: ");
    getchar();
    fgets(PC1.data,sizeof(PC1.data),stdin);

    PC1.fileLenSum=sizeof(PC1.data)+sizeof(PC1.other)+sizeof(PC1.destinationAddress)+sizeof(PC1.sourceAddress);

    printf("Time at which the packet is sent from PC1 to PC2 if Route 2 is selected = %fs\n",(float)PC1.fileLenSum/line[2]);

    int temp=PC1.sourceAddress[0];
    PC1.sourceAddress[0]=TurnOnK(PC1.sourceAddress[0],8);
    if(temp==PC1.sourceAddress[0])
        PC1.sourceAddress[0]=TurnOffK(PC1.sourceAddress[0],8);

    temp=PC1.destinationAddress[3];
    PC1.destinationAddress[3]=TurnOnK(PC1.destinationAddress[3],0);
    if(temp==PC1.destinationAddress[3])
        PC1.destinationAddress[3]=TurnOffK(PC1.destinationAddress[3],0);

    printf("IP if error orcur: \n");
    printf("%d.%d.%d.%d\n",(PC1.sourceAddress[0]) ,(PC1.sourceAddress[1]),(PC1.sourceAddress[2]),(PC1.sourceAddress[3]));
    printf("%d.%d.%d.%d\n",(PC1.destinationAddress[0]), (PC1.destinationAddress[1]),(PC1.destinationAddress[2]),(PC1.destinationAddress[3]));
    printf("%d.%d.%d.%d\n",Dec2Bin(PC1.sourceAddress[0]) ,Dec2Bin(PC1.sourceAddress[1]),Dec2Bin(PC1.sourceAddress[2]),Dec2Bin(PC1.sourceAddress[3]));
    printf("%d.%d.%d.%d\n",Dec2Bin(PC1.destinationAddress[0]), Dec2Bin(PC1.destinationAddress[1]),Dec2Bin(PC1.destinationAddress[2]),Dec2Bin(PC1.destinationAddress[3]));

}

int main()
{
    //Ex1();
    //Ex2();
    Ex3();
    return 1;
}