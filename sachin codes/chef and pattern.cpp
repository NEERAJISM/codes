#include<iostream>
#include<stdio.h>
#define m 1000000007
using namespace std;

long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y)%c;      //  or call  mulmod(x,y,c);
		}
		y=(y*y)%c;          //  or call  mulmod(y,y,c);
		b=b/2;
	}
	return x%c;
}


int main()
{
	int t;
	long long int n,k,i,temp,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&k,&n);
		if(n==1)
		printf("1\n");
		else if(n==2)
		printf("%lld\n",k);
		else
		{
			temp=modular_exponentiation(2,n-3,m-1);
			res=modular_exponentiation(k,temp,m);
			printf("%lld\n",res);
		}
	}
	return 0;
}
