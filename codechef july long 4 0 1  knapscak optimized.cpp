#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int t,n,k,i,m,b[100009],rust[100009],n1,temp,min1[100009],l,r,c,a[100009],t2;

long long int knapsack(int n,int wt[],int val[],int k)
{
    long long int dp[2][k+1];

    memset(dp[0], 0, sizeof(dp[0]));
    for(int i = 1; i <= n; i++)
    {
        long long int *cur = dp[i&1],*prev = dp[!(i&1)];
        for(int j = 0; j <= k; j++)
        {
            cur[j] = (wt[i] > j) ? prev[j] : (prev[j]>prev[j-wt[i]] + val[i] ? prev[j]:prev[j-wt[i]] + val[i]);
        }
    }
    return dp[n&1][k];
}

int main()
{
    long long int total;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&m);
        n1=0;
        total = 0;

        min1[0] = 1000;
        for(i=1;i<=n;i++)
        {
            min1[i] = 1000;
            scanf("%d",&t2);
            a[i] = t2;
            total+=t2;

            if(t2<0)
            {
                rust[i] = n1;
                b[n1] = -1*t2;
                n1++;
            }
        }

        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&l,&r,&c);
            if(c<=k)
                for(l;l<=r;l++)
                {
                    if(a[l]<0 && min1[rust[l]] > c)
                        min1[rust[l]] = c;
                }
        }

        long long int output = knapsack(n1,min1,b,k);
        printf("%lld\n",total+output);
    }
return 0;
}
