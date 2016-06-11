#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,i,j,t;
    scanf("%lld",&t);

    while(t>0)
    {
        scanf("%lld",&n);

        while(n%2==0)
            n=n/2;

        for(i=3;i<=sqrt(n);i=i+2)
        {
            while(n%i==0)
                n=n/i;

        }
        if(n>2)
            printf("%lld\n",n);
        t--;
    }
return 0;
}



