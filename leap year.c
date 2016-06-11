#include<stdio.h>
int main()
{ int yr,a,b,c;
printf("enter the year\n");
scanf("%d",&yr);

a=yr%4;
b=yr%100;
c=yr%400;

if(a==0&&b!=0)
    printf("it is a leap year\n");
else if(c==0)
    printf("it is a leap year\n");
else
    printf("it is not a leap year\n");
return 0;
}

