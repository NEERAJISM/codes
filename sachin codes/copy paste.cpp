#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i,x,count;
	scanf("%d",&t);
	while(t--)
	{
		int hash[100002]={0};
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			hash[x]++;
		}
		count=0;
		for(i=0;i<100002;i++)
		{
			if(hash[i]!=0)
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
