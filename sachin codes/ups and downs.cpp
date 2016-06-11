#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,a[100000],b[100000],i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		if(n%2==0)
		{
			for(i=0;i<n;i=i+2)
			{
			    b[i]=a[i/2];
			    b[i+1]=a[(i/2)+(n/2)];
			}
		}
		else
		{
			for(i=0;i<n;i=i+2)
			{
			    b[i]=a[i/2];
			    b[i+1]=a[(i/2)+(n/2)+1];
			}
		}
		for(i=0;i<n;i++)
		printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}
