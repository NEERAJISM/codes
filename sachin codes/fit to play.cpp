#include<iostream>
#include<stdio.h>
using namespace std;
int a[100002];
int main()
{
	int t,n,i,c,maxdiff,smallest,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		maxdiff=0;smallest=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]<smallest)
			smallest=a[i];
			c=a[i]-a[i-1];
			if(c>maxdiff)
			maxdiff=c;
			d=a[i]-smallest;
			if(d>maxdiff)
			maxdiff=d;
		}
		if(maxdiff==0)
		printf("UNFIT\n");
		else
		printf("%d\n",maxdiff);
	}
	return 0;
}
