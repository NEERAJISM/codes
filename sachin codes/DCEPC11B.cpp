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
	long long int n,p,s,i,x,y,z;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&p);
		s=1;
		if(n>=p)
		{
			printf("0\n");
		}
		else
		{
			for(i=n+1;i<=p-1;i++)
			{
				s=(s*i)%p;
			}
			x=modular_exponentiation(s,p-2,p);
			y=-x;
			if(y<0)
			z=p+y;
			printf("%lld\n",z);
		}
		
	}
	return 0;
}
