#include<bits/stdc++.h>
using namespace std;
int main()
{
	int dp[20][20];
	
	int i,j;
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(j==0||j==i)
			dp[i][j]=1;
			else
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	
	int t,n,r;
	cin>>t;
	while(t--)
	{
		cin>>n>>r;
		cout<<dp[n][r]<<endl;
	}
	return 0;
}
