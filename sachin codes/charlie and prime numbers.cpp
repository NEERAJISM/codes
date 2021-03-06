#include<iostream>
#include<stdio.h>
using namespace std;

int a[5000005],primes[5000005],k=0;

void SieveOfEratosthenes(int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	a[i]=i;
	for(i=2;i<=n;i++)
	{
		if(a[i]!=0)
	 	{
	 		primes[k++]=i;
	 		j=2;
	 		while((i*j)<=n)
	 		{
	 			a[i*j]=0;
	 			j++;
	 		}
	 	}
	}
}


int main()
{
	int t,n,m,i;
	long long int s;
	SieveOfEratosthenes(5000002);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		s=0;
		for(i=0;i<k;i++)
		{
			if(primes[i]>=n&&primes[i]<=m)
			s+=primes[i];
		}
		printf("%lld\n",s);
	}
	return 0;
}
