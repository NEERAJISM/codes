#include<iostream>
#include<stdio.h>
using namespace std;
int a[102];
int maximum(int n)
{
	int i,max=a[0],pos=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		    pos=i;
		}
	}
	return pos;
}
int check(int pos,int n)
{
	int i,count=0,max=a[pos];
	for(i=0;i<n;i++)
	{
		if(a[i]==max)
		count++;
	}
	return count;
}
int main()
{
	int t,n,i,x,count,pos;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		x=0;
		do
		{
			pos=maximum(n);
			count=check(pos,n);
			for(i=0;i<n;i++)
			{
				if(i!=pos)
				a[i]++;
			}
			x++;
		}
		while(count!=n);
		printf("%d\n",x-1);
		for(i=0;i<102;i++)
		a[i]=0;
	}
	return 0;
}
