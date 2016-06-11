#include<bits/stdc++.h>
using namespace std;

long long int dp[100002];
int last[30];

int main()
{
	int t,i,x,n;
	char s[100002];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<=100002;i++)
		dp[i]=0;
		for(i=0;i<=28;i++)
		last[i]=0;
		
		cin>>s;
		n=strlen(s);
		char ss[n+2];
		
		for(i=0;i<n;i++)
		ss[i+1]=s[i];
		
		dp[0]=1;
	
		for(i=1;i<=n;i++)
		{
			if(last[ss[i]-'A']==0)
			{
				dp[i]=(dp[i-1]+dp[i-1])%1000000007;
				if(dp[i]<0)
				dp[i]+=1000000007;
				last[ss[i]-'A']=i;
			}
			else
			{
				dp[i]=(dp[i-1]+dp[i-1])%1000000007;
				if(dp[i]<0)
				dp[i]+=1000000007;
				dp[i]=(dp[i]-dp[last[ss[i]-'A']-1])%1000000007;
				if(dp[i]<0)
				dp[i]+=1000000007;
				last[ss[i]-'A']=i;
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
