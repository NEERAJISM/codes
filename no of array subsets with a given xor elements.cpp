#include <bits/stdc++.h>
using namespace std;
#define mod 100000007
int main()
{
    int n,i,j,k,m,ttt,a[1030],b[1030],res,tc = 1,cnt,mx = 0,m1,m2,pow2[1030];
    vector<vector<int> > dp(1030,vector<int>(10300,0));

    pow2[0] = 1;
    for(i=1;i<=1000;i++)
        pow2[i] = (pow2[i-1]*2)%mod;

    scanf("%d",&ttt);
    while(tc<=ttt)
    {
        mx = 0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i] > mx)
                mx = a[i];
        }

        for(i=0;i<m;i++)
            scanf("%d",&b[i]);

        dp[0][0] = 1;
        m2 = (1 <<  (int)(log2(mx)+1)) - 1;

        for(i=1;i<=n;i++)
            for(j=0;j<=m2;j++)
                dp[i][j] = (dp[i-1][j]+dp[i-1][(j^a[i-1])])%mod;

        cnt = 0;
        for(i=0;i<m;i++)
            cnt = (cnt+dp[n][b[i]])%mod;

        res = pow2[n];
        printf("Case %d: %d\n",tc,(res-cnt));
        tc++;
        dp.clear();
    }
return 0;
}
