#include <iostream>
#include <cstdio>
using namespace std;
int t,n,k,i,m,b[100090],rust[100090],n1,temp,min1[100090],l,r,c,a[100090],t2;

long long int knapsack(int n,int wt[],int val[],int k)
{
    int dp[100000][5000],t3,t4;
    int i,w;
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=k;w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(wt[i-1] <= w)
            {
                t3 = (val[i-1] + dp[i-1][w-wt[i-1]]);
                t4 = dp[i-1][w];
                dp[i][w] = t3>t4?t3:t4;
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][k];
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
