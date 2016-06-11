#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		c=a>b?a:b;
		printf("%d %d\n",c,a+b);
	}
	return 0;
}
