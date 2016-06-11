#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int maximum(int b,int mb)
{
	int z=mb>b?mb:b;
	return z;
}

int main()
{
	int t,n,i,l,b,mb;
	char c[100002];
	scanf("%d",&t);
	while(t--)
	{
		cin>>c;
		l=strlen(c);
		b=0;
		mb=0;
		for(i=0;i<l;i++)
		{
			if(c[i]=='(')
			b=b+1;
			else
			b=b-1;
			mb=maximum(b,mb);
		}
		for(i=0;i<mb;i++)
		printf("(");
		for(i=0;i<mb;i++)
		printf(")");
		printf("\n");
	}
	return 0;
}
