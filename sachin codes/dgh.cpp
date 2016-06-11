#include<stdio.h>
#include<iostream>
using namespace std;
int h[5000010];
int main()
{
	int x,y,z,t,i,c=0;
	scanf("%d%d%d",&x,&y,&z);
	for(i=0;i<x;i++)
	{
			scanf("%d",&t);
			h[t]++;
	}
	for(i=0;i<y;i++)
	{
			scanf("%d",&t);
			h[t]++;
	}
	for(i=0;i<z;i++)
	{
			scanf("%d",&t);
			h[t]++;
	}
	for(i=0;i<5000001;i++)
		if(h[i]>1)
			c++;
	printf("%d\n",c);
	for(i=0;i<5000001;i++)
		if(h[i]>1)
			printf("%d\n",i);
return 0;	
}
