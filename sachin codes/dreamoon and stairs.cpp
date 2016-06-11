#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,m,a,b,c,d,e,num;
	scanf("%d%d",&n,&m);
	if(n<m)
	printf("-1\n");
	else
	{
		a=n/2;
		b=n%2;
		c=a+b;
		if(c%m==0)
		printf("%d\n",c);
		else
		{
			d=c%m;
			e=m-d;
			num=c+e;
			printf("%d\n",num);
		}
	}
	return 0;
}
