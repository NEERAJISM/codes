#include<iostream>
#include<stdio.h>
using namespace std;

long long int fib[1000002];

long long int fibonacci(int x)
{
	if(x==0)
	return 0;
	fib[0]=0;
	fib[1]=1;
	if(fib[x]!=0)
	return fib[x]; 
	else 
	fib[x]=(fibonacci(x-1)%1000000007)+(fibonacci(x-2)%1000000007);
	fib[x]=fib[x]%1000000007;
	return fib[x];
}

int main()
{
	int t,n,m,i,diff;
	long long int s1,s2;
	for(i=0;i<=1000002;i++)
		fibonacci(i);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
	    s1=fib[2*n];
	    s2=fib[(2*m)-1]-1;
		
	    diff=s1-s2;
		printf("%d\n",diff);
	}
	return 0;
}

