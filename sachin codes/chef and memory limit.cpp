#include<bits/stdc++.h>
using namespace std;

long long int a[100003];

int main()
{
	int n,i,t;
	long long int x,max,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		
		max=a[0]; ans=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]-a[i-1]>0)
			ans=ans+(a[i]-a[i-1]);
			
		}
		printf("%lld\n",ans);
	}
	return 0;
}
