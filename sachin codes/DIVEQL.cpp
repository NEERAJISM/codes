#include<iostream>
#include<stdio.h>
#define mod 1000000007
using namespace std;

long long mulmod(long long int a,long long int b,long long int c)
{
	long long int x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x+y)%c;
		}
		y=(y+y)%c;
		b=b/2;
	}
	return x%c;
}

long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y)%c;    //mulmod(x,y,c);
		}
		y=(y*y)%c;    //mulmod(y,y,c);
		b=b/2;
	}
	return x%c;
}


int main()
{
	int t,i;
	long long int n,p,z,x,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&p);
		a=modular_exponentiation(p,n,mod);
		a=a-1;
		x=modular_exponentiation(p,n-1,mod);
		c=modular_exponentiation(p-1,mod-2,mod);
		z=(a*c)%mod;
		printf("%lld %lld\n",z,x);
	}
	return 0;
}
