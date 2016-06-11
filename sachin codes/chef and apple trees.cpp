#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i,x,steps;
	scanf("%d",&t);
	while(t--)
	{
		int a[100002]={0};
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		steps=0;
		for(i=1;i<=100000;i++)
		{
			if(a[i]!=0)
			steps++;
		}
		printf("%d\n",steps);
	}
	return 0;
}
