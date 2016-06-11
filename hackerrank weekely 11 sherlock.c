#include<stdio.h>
#include<math.h>
#define MOD 1000000007
int main()
{
    long long int sum,i,n,t;
    scanf("%lld",&t);
    while(t>0)
    {
        scanf("%lld",&n);
        if(n==0)
            printf("4\n");
        else
        {
            sum=1;
            for(i=0;i<n;i++)
                sum=(sum*2)%MOD;

            printf("%lld\n",sum%MOD);
            sum=(sum+4)%MOD;
            printf("%lld\n",sum);
        }
        t--;
    }
return 0;
}

