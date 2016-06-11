#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a,b,c,max;
	scanf("%d%d%d",&a,&b,&c);
	if(a!=1&&b!=1&&c!=1)
	{
		max=a*b*c;
	}
	else
	{
		if(a!=1&&b!=1&&c==1)
		max=a*(b+c);
		if(a!=1&&c!=1&&b==1)
		{
			if(a>c)
			max=a*(b+c);
			else
			max=(a+b)*c;
		}
		if(b!=1&&c!=1&&a==1)
		max=(a+b)*c;
		if(a==1&&b==1&&c!=1)
		max=(a+b)*c;
		if(a!=1&&b==1&&c==1)
		max=a*(b+c);
		if(a==1&&b!=1&&c==1)
		max=a+b+c;
		if(a==1&&b==1&&c==1)
		max=3;
	}
	printf("%d\n",max);
}
