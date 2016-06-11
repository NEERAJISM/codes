#include<iostream>
#include<cstdio>
using namespace std;
long long int a[100000];
int main()
{
    long long int t,n,k,q,l,r,tot,i,j,t1,n1,k1;
    char s[100007];
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld%lld%lld",&n,&k,&q);
        scanf("%s",&s);
        n1=0;
        for(i=1;i<=n;i++)
        {
            if(s[i-1]=='1')
            {
                a[i]=n1+1;
                n1++;
            }
            else
                a[i]=n1;
        }

        while(q--)
        {
            tot=0;
            scanf("%lld%lld",&l,&r);

            n=r-l+1;
            n1=n;
            k1=k;
            t1=k;

            while(t1--)
            {
                tot=tot+n1;
                n1--;
            }

            n1=n;
            t1=n-k1;

            while(t1--)
            {
                i=l;
                j=i+k1;
                while(j<=r)
                {
                    if(a[j]-a[i-1]<=k&&(j-i+1-a[j]+a[i-1])<=k)
                        tot++;

                    i++;
                    j=i+k1;
                }
                k1++;
            }
            printf("%lld\n",tot);
        }
    }
    return 0;
}
