#include<iostream>
#include<stdio.h>
using namespace std;
int a[100002];
int main()
{
	int t,n,k,q,i,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&q);
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&l,&r);
			if(k>=l&&k<=r)
			k=r-(k-l);
		}
		printf("%d\n",k);
		
	}
	return 0;
}
