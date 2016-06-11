#include<iostream>
#include<stdio.h>

using namespace std;

long long int fac[200003];    // after n=22 it goes out of range
long long int m=1000000007;
long long int Q=500000003;

long long int factorial(long long int x)
{
	if(x==0||x==1)
	return 1;
	fac[0]=1;
	fac[1]=1;
	if(fac[x]!=0)
	return fac[x];
	else 
	fac[x]=(x*factorial(x-1))%Q;
	return fac[x];
}


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


long long int ncr(long long int x,long long int y)
{
	long long int a,b,c,d,e,f;
	a=factorial(x-1);//cout<<"a="<<a<<endl;
	b=factorial(y-1);//cout<<"b="<<b<<endl;
	c=factorial(x-y);//cout<<"c="<<c<<endl;

	d=modular_exponentiation(b,Q-2,Q);//cout<<"d="<<d<<endl;
	e=modular_exponentiation(c,Q-2,Q);//cout<<"e="<<e<<endl;
	f=(a*d)%Q;
	f=(f*e)%Q;
	return f;
}

int main()
{
	int t;
	long long int a,b,n,e,E,temp,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		if(n==0)
		printf("1\n");
		else
		{
			e=ncr((2*n),n);//cout<<"e="<<e<<endl;
			E=(2*e)%(m-1);cout<<"E="<<E<<endl;
		//	E=(Q+(e*(Q+1)%(m-1))%(m-1));
			temp=modular_exponentiation(E,b,(m-1));//cout<<"temp="<<temp<<endl;
			res=modular_exponentiation(a,temp,m);
			printf("%lld\n",res);
		}
	}
	return 0;
}
