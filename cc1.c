#include<stdio.h>
int main()
{
    long long int t,d1,i,d,max,a[100000],n,k;

    scanf("%lld",&t);

    while(t-->0)
    {
        scanf("%lld%lld",&n,&k);
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&d);
            a[i]=k/d;
        }

        for(i=0;i<n;i++)
        {
            scanf("%lld",&d);
            d1=a[i]*d;
            max=(d1>max?d1:max);
        }

        printf("%lld\n",max);
    }
return 0;
}
