#include<iostream>
#include<stdio.h>
using namespace std;
 long long int a[100003],sum[100003],h[1000003],g[1000003];
int main()
{
//	int t;
   long long int t,n,p,i,x,max;
	scanf("%lld",&t);
	
	while(t--)
	{	
		scanf("%lld%lld",&n,&p);
		for(i=0;i<=n;i++)
		{
			sum[i]=0;
			a[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i]=(sum[i-1]+a[i])%p;
		}
		if(sum[n]==0)
		printf("%lld\n",n);
		else
		{
			
		
		for(i=0;i<=1000002;i++)
		{
			h[i]=0;
			g[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(h[sum[i]]==0)
			h[sum[i]]=i;
		}
		for(i=1;i<=n;i++)
		{
			g[sum[i]]=i;
		}
		max=0;
		for(i=0;i<=1000002;i++)
		{
			x=g[i]-h[i];
			if(x>max)
			max=x;
		}
		printf("%lld\n",max);}
	}
	return 0;
}
