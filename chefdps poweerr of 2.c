#include<stdio.h>
int main()
{
    long long int a,r,b[100000],t,i,n;

    scanf("%lld",&a);
    n=-1;
    while(a!=0)
    {
        t=1;
        while(t<a)
            t=t*2;

        if(t==a)
        {
            n++;
            b[n]=t;
            break;
        }
        else
        {
            r=a-t/2;
            n++;
            b[n]=t/2;
            a=r;
        }
    }
    for(i=n;i>=0;i--)
        printf("%lld ",b[i]);


return 0;
}
