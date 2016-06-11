#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,n,m,k,cnt = 0,a,b,c,cnt2,vl,vl1,vl2,qt;
    scanf("%lld%lld%lld%lld",&n,&a,&b,&c);

    vl2 = n/a;
    qt  = n%a;
    while(qt >= b)
    {
        cnt2 = qt/b;
        vl2 += cnt2;
        qt = qt%b;
        qt += (c*cnt2);
    }

    vl = n;
    while(vl >= b)
    {
        cnt2 = vl/b;
        cnt += cnt2;
        vl = vl%b;
        vl += (c*cnt2);
    }

    if(vl>=a)
        cnt += (vl/a);

    if(vl2 > cnt)
        cnt = vl2;

    printf("%lld",cnt);
    return 0;
}
