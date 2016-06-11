#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,i,a[101],x,pos,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		scanf("%d",&k);
		x=a[k-1];
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			if(a[i]==x)
			{
			   pos=i;
			   break;
			}
		}
		printf("%d\n",pos+1);
	}
	return 0;
}
