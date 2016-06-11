#include<iostream>
#include<stdio.h>
using namespace std;
int gcd(int x, int y)
{
	if (y==0)
		return x;
	else
		return gcd(y,x%y);
}
int main()
{
	int t,n,a[1000],i,g;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		int z=gcd(a[0],a[1]);
		if(n==1)printf("1\n");
		else if(n==2)printf("%d\n",z);
		else if(n>2)
		{
		
		i=2;
		while(i<n)
		{
			g=gcd(z,a[i]);
			z=g;
			i++;
		}
		printf("%d\n",g);}
	}
	return 0;
}
