#include<stdio.h>
int main()
{
	long long int t,n,op;
	scanf("%lld",&t);

	while(t-->0)
	{
		scanf("%lld",&n);
		op =((3*n+2)*(n-1)*(n+1)*(n))/12;		
		printf("%lld\n",op);
	}
return 0;
}
