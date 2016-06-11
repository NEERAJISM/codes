#include<iostream>
#include<stdio.h>
using namespace std;

int a[10007],b[10007];


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
	int i,n,x,y,z,C;
	SieveOfEratosthenes(10003);
/*	cout<<k<<endl;
	for(i=0;i<k;i++)
	cout<<primes[i]<<"   ";	*/
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<10007;i++)
		b[i]=0;
		for(i=2;i<=n;i++)
		{
			x=i;
			while(a[x]!=1)
			{
				b[a[x]]++;
				x=x/a[x];
			}
			b[x]++;
		}
		C=0;
		for(i=0;i<10007;i++)
		{
			if(b[i]!=0)
			{
				C++;
			}
		}
		 int K=0;
		for(i=0;i<10007;i++)
		{
			if(b[i]!=0)
			{
				K++;
				if(K!=C)
				printf("%d^%d * ",i,b[i]);
				else
				printf("%d^%d",i,b[i]);
				
				
			}
		}
		printf("\n");
	}
	return 0;
}
