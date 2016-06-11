#include<bits/stdc++.h>
using namespace std;

#define inf 100000
int main()
{
	int t,n,x,y,i;
	scanf("%d",&t);
	    int dp[1002];
	    for(i=1;i<=1001;i++)
	    dp[i]=inf;
		dp[0]=0;
		
		for(i=1;i<=1001;i++)
		{
			if(i>=1)
			dp[i]=min(dp[i],dp[i-1]+1);
			if(i>=5)
			dp[i]=min(dp[i],dp[i-5]+1);
			if(i>=7)
			dp[i]=min(dp[i],dp[i-7]+1);
			if(i>=10)
			dp[i]=min(dp[i],dp[i-10]+1);
		}
	while(t--)
	{
		scanf("%d",&n);
		
		
		printf("%d\n",dp[n]);
	}
	return 0;
}
