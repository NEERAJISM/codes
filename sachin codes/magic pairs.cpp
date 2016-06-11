#include<iostream>
#include<stdio.h>
using namespace std;
int a[100002];
int main()
{
	long long int t,n,i;
	char c;
	long long int s,max,d,x;
	char v;
	scanf("%lld",&t);
	while(t--)
	{
		
		scanf("%lld",&n);
		do
		{
			v=getchar_unlocked();
		}
		while(v!='\n');
		max=(n*(n-1))/2;
		printf("%lld\n",max);
	}
	return 0;
}
