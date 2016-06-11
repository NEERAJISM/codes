#include <bits/stdc++.h>
using namespace std;
long long int a[100005][2],dd1,dd2;
int main()
{
    int n,p,x,y,tmp,cnt,i,ls,lp;
    long long int rsltn,rsltd;
    double res = 0;
    scanf("%d%d",&n,&p);

    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);

        if(y<p)
        {
            a[i][0] = 0;
            a[i][1] = y-x+1;
            continue;
        }

        ls = (x-1)/p;
        lp = y/p;
        cnt = lp-ls;

        dd1 = cnt;
        dd2 = y-x+1;
        a[i][0] = dd1;
        a[i][1] = dd2;
    }

    for(i=0;i<(n-1);i++)
    {
        rsltd = a[i][0]*a[i+1][0] + (a[i][1]-a[i][0])*a[i+1][0] + a[i][0]*(a[i+1][1]-a[i+1][0]);
        rsltn = a[i][1]*a[i+1][1];

        res += (1.0*rsltd)/(1.0*rsltn);
    }
    rsltd = a[0][0]*a[n-1][0] + (a[0][1]-a[0][0])*a[n-1][0] + a[0][0]*(a[n-1][1]-a[n-1][0]);
    rsltn = a[0][1]*a[n-1][1];

    res += (1.0*rsltd)/(1.0*rsltn);
    res*=2000;

    cout<<fixed<<setprecision(6)<<res;
    return 0;
}
