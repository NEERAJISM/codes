#include<iostream>
#include<stdio.h>
using namespace std;
char c[1000];
int main()
{
	int t,n,x,i,d,e,count,num;
	scanf("%d",&t);
	while(t--)
	{
		x=0;count=0;num=0;
		scanf("%d",&n);
		cin>>c;
		if(c[0]!='1'&&c[1]!='1')
		d=1;
		else
		d=0;
		if(c[n-1]!='1'&&c[n-2]!='1')
		e=1;
		else
		e=0;
		for(i=0;i<n;i++)
		{
			if(c[i]=='0')
			x++;
		}
		if(x==n)
		printf("%d\n",n);
		else
		{
		
		for(i=0;i<n;i++)
		{
			if(c[i]=='0')
			count++;
			else
			count=0;
			if(count>2)
			num++;
		}
		printf("%d\n",num+d+e);
		}
	}
	return 0;
}
