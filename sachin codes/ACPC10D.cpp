#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t=0,p,q,r,i;
	while(1)
	{
		t++;
		scanf("%d",&n);
		if(n==0)
		break;
		
		int  a[n+1][4];
		int dp[n+1][4];
		
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		
		dp[1][1]=a[1][1];
		dp[1][2]=a[1][2];
		dp[1][3]=a[1][2]+a[1][3];
		
		for(i=2;i<=n;i++)
		{
			if(i!=2)
			dp[i][1]=min(a[i][1]+dp[i-1][1] , a[i][1]+dp[i-1][2]);
			else
			dp[i][1]=a[i][1]+dp[i-1][2];
			if(i!=2)
			dp[i][2]=min(min(a[i][2]+dp[i-1][1] , a[i][2]+dp[i-1][2]) , min(a[i][2]+dp[i-1][3] , a[i][2]+dp[i][1]));
			else
			dp[i][2]=min( a[i][2]+dp[i-1][2] , min(a[i][2]+dp[i-1][3] , a[i][2]+dp[i][1]));
			
			dp[i][3]=min(a[i][3]+dp[i-1][3] , min(a[i][3]+dp[i-1][2],dp[i][2]+a[i][3]));
		}
		cout<<t<<". "<<dp[n][2]<<endl;
	}
	return 0;
}
