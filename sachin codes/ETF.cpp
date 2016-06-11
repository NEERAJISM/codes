#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

int a[1000007];

void SieveOfEratosthenes(int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	a[i]=i;
	for(i=2;i<=n;i++)
	{
		if(a[i]==i)
	 	{
	 		//a[i]=i-1;
	 		j=2;
	 		while((i*j)<=n)
	 		{
	 			a[i*j]=(a[i*j]/i)*(i-1);
	 			j++;
	 		}
	 	}
	}
}

int main()
{
	int t,n,i,x;
	SieveOfEratosthenes(1000002);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		printf("1\n");
		else
		{
		
			x=a[n];
			if(x==n)
			x=x-1;
			printf("%d\n",x);
		}
	}	
	return 0;
}
