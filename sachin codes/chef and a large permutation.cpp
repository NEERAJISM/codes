#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,s,a[100002],i,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<k;i++)
		scanf("%d",&a[i]);
		
		s=n*(n+1);
		s=s/2;
		if(s%2==0)
		printf("Chef\n");
		else
		printf("Mom\n");
	}
	return 0;
}
