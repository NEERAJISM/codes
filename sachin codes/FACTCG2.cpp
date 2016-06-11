#include<iostream>
#include<stdio.h>
using namespace std;

int a[10000007],b[1000000];


void SieveOfEratosthenes(int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	a[i]=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]==1)
	 	{
	 		j=2;
	 		while((i*j)<=n)
	 		{
	 			a[i*j]=i;
	 			j++;
	 		}
	 	}
	}
}


int main()
{
	int i,n,x,y,z;
	SieveOfEratosthenes(10000001);
/*	cout<<k<<endl;
	for(i=0;i<k;i++)
	cout<<primes[i]<<"   ";	*/
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		printf("1\n");
		else
		{
			x=n;
			z=0;
			while(a[x]!=1)
			{
				b[z++]=a[x];
				x=x/a[x];
			}
			b[z++]=x;
			b[z++]=1;
			for(i=z-1;i>0;i--)
			printf("%d x ",b[i]);
		
			printf("%d\n",b[0]);
		}
		
	}
	return 0;
}
