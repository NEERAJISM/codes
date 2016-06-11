#include<stdio.h>
#define m 1000000007
int pow1(int x,int y)
{
    int t;
    if(y==0)
        return 1;
    else if(y%2>0)
        return (x*pow1(x,y-1))%m;
    else
    {
        t=pow1(x,y/2)%m;
        return (t*t)%m;
    }
}

int main()
{
    int a,b,result;

    scanf("%d%d",&a,&b);

    result=pow1(a,b)%m;

    printf("%d ",result);

    return 0;
}
