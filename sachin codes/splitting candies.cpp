#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long int t,n,k,a,b;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		if(n==0)
		printf("0 0\n");
		else if(k==0)
		printf("0 %lld\n",n);
		else
		{
		
		a=n/k;
		b=n%k;
		printf("%lld %lld\n",a,b);}
	}
	return 0;
}
