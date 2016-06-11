#include<bits/stdc++.h>
using namespace std;

int a[100][100],dp[100][100];

int main()
{
	int t,n,m,i,j;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<100;i++)
		{
			for(j=0;j<100;j++)
			dp[i][j]=0;
		}
		
		scanf("%d%d",&n,&m);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(i==0&&j>0)
				dp[i][j]=a[i][j] + max(dp[i][j-1],0);
				else if(j==0&&i>0)
				dp[i][j]=a[i][j] + max(dp[i-1][j],0);
				else
				dp[i][j]=a[i][j] + max(dp[i-1][j],dp[i][j-1]);
			}
		}
		
		printf("%d\n",dp[n-1][m-1]);
	}
	return 0;
}
