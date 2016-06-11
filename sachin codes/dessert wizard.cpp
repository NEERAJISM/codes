#include<bits/stdc++.h>
using namespace std;
#define inf 1000000002

long long int a[10003];

long long int func_max(int n)
{
	long long int max1=0,max2=-inf,flag=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]>0)
		flag=1;
		
		max1+=a[i];
		if(a[i]<0)
		max1=0;
		if(max1>max2)
		max2=max1;
	}
	if(flag)
	return max2;
	else
	{
		max2=-inf;
		for(i=0;i<n;i++)
		{
			if(a[i]>max2)
			max2=a[i];
		}
		return max2;
	}
}

long long int func_min(int n)
{
	long long int min1=0,min2=inf,flag=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		flag=1;
		
		min1+=a[i];
		if(a[i]>0)
		min1=0;
		if(min1<min2)
		min2=min1;
	}
	if(flag)
	return min2;
	else
	{
		min2=inf;
		for(i=0;i<n;i++)
		{
			if(a[i]<min2)
			min2=a[i];
		}
		return min2;
	}
}

int main()
{
	int t,i,n;
	long long int x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		
		x=func_max(n)-func_min(n);
		printf("%lld\n",x);
	}	
	return 0;
}
