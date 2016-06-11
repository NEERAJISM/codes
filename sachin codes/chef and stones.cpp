#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,i,n,x;
	long long int a[100002],b[100002];
	long long int r,max,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		scanf("%lld",&b[i]);
		
		max=0;
		for(i=0;i<n;i++)
		{
			x=k/a[i];
			r=x*b[i];
			if(r>max)
			max=r;
		}
		printf("%lld\n",max);
	}
	return 0;
}
