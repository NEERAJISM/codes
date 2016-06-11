#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,m,a[100],b[100],i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		int max=a[0];
		for(i=0;i<n;i++)
		{
			if(a[i]>max)
			max=a[i];
		}
		int s=0;
		for(i=0;i<n;i++)
		{
			b[i]=max-a[i];
			s+=b[i];
		}
		if((m-s)%n==0)
		printf("Yes\n");
		else
		printf("No\n");
		
		
	}
	return 0;
}
