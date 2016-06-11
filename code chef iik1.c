#include<stdio.h>
int main()
{
    long long int t,i,n,k,sum,count;
    scanf("%lld",&t);
    while(t-->0)
    {
        scanf("%lld%lld",&n,&k);
        count =0;
        while(n>=k)
        {
            sum=k;
            while(n>=sum)
                sum=sum*sum;

            count++;

            n=n-sum ;
        }
        if(n>0)
            count+=n;

        printf("%lld\n",count);
    }
    return 0;
}
