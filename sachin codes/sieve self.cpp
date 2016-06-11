#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

int a[100007],primes[10000],k=0;

void SieveOfEratosthenes(int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		if(a[i]==0)
	 	{
	 		primes[k++]=i;
	 		j=2;
	 		while((i*j)<=n)
	 		{
	 			a[i*j]=1;
	 			j++;
	 		}
	 	}
	}
}

int main()
{
	int t,n,i,x;
	cout<<"enter the limit\n";
	scanf("%d",&n);
	SieveOfEratosthenes(n);
	
	for(i=0;i<k;i++)
	cout<<primes[i]<<"   ";
	cout<<endl<<"number = "<<k;	
    return 0;
}
