#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j,x,count;

	char s[5005];
	while(1)
	{
		long long ans[5005]; int flag=0;
		cin>>s;
		n=strlen(s);
		if(s[0]=='0')
		break;
		
		for(i=0;i<=n;i++)
		ans[i]=0;
		
		ans[0]=1;
	
		
		for(i=1;i<n;i++)
		{
			x=(s[i-1]-'0')*10+(s[i]-'0');
			if(s[i]!='0')
			ans[i]=ans[i-1];
			if(x>9&&x<=26)
			ans[i]+=ans[(i-2)<0?0:(i-2)];
			
		}
		if(flag!=1)
		printf("%lld\n",ans[n-1]);
	}
	return 0;
}
