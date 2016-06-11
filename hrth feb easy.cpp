#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define ll long long

#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=e;i>=s;i--)

#define vi vector<int>
#define vvi vector<vector<int> >

// end of template

int main()
{
    int i,j,k,n,t,mn,sm,r,ssq = 1,a[1003],val = 1;
    double res;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld%lld",&n,&r);
        val *= (((n*(n+1))*(n*(n+1)))/4);
        ssq *= (r*((n*(n+1)*(2*n+1))/6));
    }

    res = (1.0*val)/(1.0*ssq);
    cout<<fixed<<setprecision(4)<<res<<"\n";
    return 0;
}

