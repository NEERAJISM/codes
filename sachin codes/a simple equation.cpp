#include<iostream>
#include<stdio.h>
using namespace std;
long long int f(long long int x)
{
	long long int r;
    if(x<0)
    return 0;
    else
    {
    
    r=((x+1)*(x+2)*(x+3));
    return r/6;}
}
int main()
{
	int t;
	long long int n,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
		long long int count=0;
		count=f(n)-f(n-a-1)-f(n-b-1)-f(n-c-1)+f(n-a-b-2)+f(n-b-c-2)+f(n-c-a-2)-f(n-a-b-c-3);
		printf("%lld\n",count);
	}
	return 0;
}
