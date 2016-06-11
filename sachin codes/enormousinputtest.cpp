#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,k;
	long long int t,c=0;
	scanf("%d%d",&n,&k);
	while(n--)
	{
		scanf("%lld",&t);
		if(t%k==0)
		{
			c++;
		}
	}
	printf("%d",c);
	return 0;
}
