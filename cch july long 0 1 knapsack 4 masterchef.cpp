#include <iostream>
#include <cstdio>
using namespace std;
int t,n,k,i,m,b[100007],rust[100007],n1,temp,min1[100007],l,r,c,a[100007],t2;
long long int dp[100007][505];

long long int knapsack(int n,int wt[],int val[],int k)
{
    int i,w;
    for(i=0;i<=n;i++)
    {
        for(w=0;w<= k;w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(wt[i-1]<=w)
                dp[i][w] = (val[i-1] + dp[i-1][w-wt[i-1]])>dp[i-1][w] ? (val[i-1] + dp[i-1][w-wt[i-1]]):dp[i-1][w];
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

        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            total+=a[i];

            if(a[i]<0)
            {
                rust[n1] = i;
                b[n1] = -a[i];
                n1++;
            }
        }

        long long int output = 0;

        if(n1!=0)
        {
            for(i=0;i<=n1;i++)
                min1[i] = 202;

            for(i=0;i<m;i++)
            {
                scanf("%d%d%d",&l,&r,&c);
                if(c<=k)
                {
                    t2 = 0;
                    while(rust[t2]<l)
                    {
                        t2++;
                    }

                    if(t2<n1)
                    {
                        while(rust[t2]<=r)
                        {
                            if(min1[t2]>c)
                                min1[t2]=c;

                            t2++;
                            if(t2==n1)
                                break;
                        }
                    }
                }
            }
            output = knapsack(n1,min1,b,k);
        }
        printf("%lld\n",total+output);
    }
return 0;
}
