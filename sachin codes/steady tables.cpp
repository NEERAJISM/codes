#include<bits/stdc++.h>
using namespace std;
#define M 1000000000

int n,m;
long long int dp[4002][4002];
long long int dprec[2002][2002];
long long int val[2002];

void nCr()
{
	for(int i=1;i<=4000;i++)
	{
		dp[i-1][0]=1;
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%M;	
		}
	}

}

void calc()
{
	val[0]=1;
	for(int i=1;i<=m;i++)
	{
		int n=m+i-1;
		int r=m-1;
		val[i]=(val[i-1]+dp[n][r])%M;
	}
}


void func()
{
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dprec[i][j]=(dprec[i][j-1]+(dp[m+j-1][m-1]*dprec[i-1][j])%M)%M;
		}
	}
}

int main()
{
	nCr();
	
	int t,i;
	long long int res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		calc();
		
		for(i=0;i<=m;i++)
		dprec[1][i]=val[i];
		
		for(i=1;i<=n;i++)
		dprec[i][0]=1;
		
		func();
		
		printf("%lld\n",dprec[n][m]);
		memset(dprec, 0, sizeof(dprec));
	}
	return 0;
}
