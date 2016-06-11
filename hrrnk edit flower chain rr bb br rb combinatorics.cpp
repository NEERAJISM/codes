#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;
long long int fact[100005];
int main()
{
    int a,b,c,d,i,cr,cb,rslt;

    fact[0] = 1;
    for(i=1 ; i<=100001 ; i++ )
        fact[i] = (fact[i-1]*i)%mod;

    scanf("%d%d%d%d",&a,&b,&c,&d);

    if((a==0) && (b == 0) && (c == 0) && (d == 0))
        printf("2");
    else
    {
        if(b==d)
        {
            rslt = fact[b-1]/fact
        }
    }
}
