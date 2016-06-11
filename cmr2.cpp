#include <bits/stdc++.h>
#define mod 997868736947
#define ull long long int
using namespace std;
ull pa[100005],pb[100005];

inline ull mul(ull a,ull b)
{
  a %= mod;
  b %= mod;
  long double res = a;
  res *= b;
  ull c = (ull)(res / mod);
  a *= b;
  a = a - c * mod;
  a = a % mod;
  if(a < 0)
    a += mod;
  return a;
}

int main()
{
    ull i,j,ttt,n,na,nb,flag,i1,c,x,y,a,b;
    ull tmp;
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
            res = (res + mul(pa[i],pb[n-i]))%mod;

        printf("%llu\n",res);
    }
return 0;
}
