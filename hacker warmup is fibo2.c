#include<stdio.h>
long long int a;
int fibo(long long int x ,long long int y )
{
    long long int f;
    f=x+y;
    if(a==f)
    {
        printf("IsFibo\n");
        return 0;
    }
    else if(f>a)
    {
        printf("IsNotFibo\n");
        return 0;
    }
    fibo(y,f);
}
int main()
{
    int t;

    scanf("%lld",&t);
    while(t-->0)
    {
        scanf("%lld",&a);
        fibo(0,1);
    }
return 0;
}

