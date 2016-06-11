#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i;
	long long int a[10000],b[10000];
	scanf("%d",&t);
	while(t--)
	{
	    int diff,c=0;   
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	    
	    b[0]=a[0];
		for(i=0;i<n-1;i++)
		{
			if(b[i]>=a[i+1])
			b[i+1]=a[i+1];
			else
			b[i+1]=b[i];
		}
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i])
			c++;
		}
		printf("%d\n",c);
	}
	return 0;
}
