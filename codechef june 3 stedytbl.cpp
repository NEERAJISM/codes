#include <iostream>
#include <cstdio>
#define mod 1000000000
using namespace std;
long long int a[2005][2005],sum,county,b[2005],c[2005],t,n,m,i,j,m1;
int main()
{
    a[0][0] = 1;
    for(i=0;i<=2004;i++)
    {
        a[1][i] = 1;
        a[i][1] = 1;
    }

    for(i=2;i<=2004;i++)
        for(j=2;j<=2004;j++)
            a[i][j] = (a[i-1][j]+a[i][j-1])%mod;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld%lld",&n,&m);

        for(i=1;i<=m+1;i++)
        {
            b[i] = a[m][i];
            c[i] = 1;
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m+1;j++)
                c[j] = (c[j]*b[j])%mod;

            sum = 0;

            for(j=1;j<=m+1;j++)
            {
                c[j] = (c[j]+sum)%mod;
                sum = c[j];
            }
        }
        printf("%lld\n",c[m+1]);
    }
return 0;
}
