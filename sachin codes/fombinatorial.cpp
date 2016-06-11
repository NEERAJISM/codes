#include<iostream>
#include<stdio.h>
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
	long long int a[100002],b[100002],x,m,n,q,i,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&q);
		for(i=1;i<=n;i++)
		{
			a[i]=modular_exponentiation(i,i,m);
		}
		for(i=2;i<=n;i++)
		{
			a[i]=(a[i]*a[i-1])%m;
		}
		for(i=1;i<=n;i++)
		{
			b[i]=modular_exponentiation(a[i],m-2,m);
		}
		while(q--)
		{
			scanf("%lld",&r);
			x=(a[n]*b[r])%m;
			x=(x*b[n-r])%m;
			printf("%lld\n",x);
		}
	}
	return 0;
}
