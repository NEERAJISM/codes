#include <bits/stdc++.h>
#define mod 997868736947
#define ull unsigned long long int
using namespace std;
ull pa[100005],pb[100005];

ull mul(ull a,ull b)
{
    if(a<=1000000000 && b <=1000000000)
    {
        ull ret = (a*b)%mod;
        return ret;
    }

    ull ret = 0;
    a = a%mod;

    while(b > 0)
    {
        if(b&1)
            ret = (ret+a)%mod;
        a = (a<<1)%mod;
        b>>=1;
    }
    return ret%mod;
}

int main()
{
    ull i,j,ttt,n,na,nb,flag,i1,c,x,y,a,b;
    unsigned long long int tmp;
    scanf("%llu",&ttt);

    pa[0] = 1;
    pb[0] = 1;

    while(ttt--)
    {
        scanf("%llu%llu%llu",&a,&b,&n);

        for(i=1;i<=n;i++)
        {
            pa[i] = mul(pa[i-1],a);
            pb[i] = mul(pb[i-1],b);
        }

        ull res = 0;
        for(i=0;i<=n;i++)
            res = (res+mul(pa[i],pb[n-i]))%mod;

    pb[0] = 1;
        printf("%llu\n",res);
    }
return 0;
}