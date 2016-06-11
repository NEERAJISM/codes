#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[2002],d[4000008];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	while(n!=0)
	{
		int c=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
	k=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				d[k]=a[i]+a[j];k++;
			}
		}
		for(i=0;i<k;i++)
		{
			for(j=0;j<n;j++)
			{
				if(d[i]<a[j])
				c++;
			}
		}
		printf("%d\n",c);
		scanf("%d",&n);
	}
	return 0;
}
