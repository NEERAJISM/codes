#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,a[100],i,sum=0,c,d;
		scanf("%d%d",&n,&x);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		sort(a,a+n);
		
		for(i=0;i<n;i++)
		sum+=a[i];
		c=sum/x;
		d=sum%x;
		if(d-a[0]>=0)
		printf("-1\n");
		else
		printf("%d\n",c);
		
		
	}
	return 0;
}
