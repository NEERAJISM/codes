#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,a[100002],i,x,count,min,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		min=100000; count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<min)
			min=a[i];
			
			count+=a[i];
		}
		if(min<2)
		printf("-1\n");
		else
		{
			ans=count-min+2;
			printf("%d\n",ans);
		}
	}
	return 0;
}
