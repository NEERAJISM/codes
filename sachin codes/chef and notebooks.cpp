#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,x,y,z,k,n,p,c,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&x,&y,&k,&n);
		z=x-y;
		int flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p,&c);
			if(p>=z&&k>=c)
			flag=1;
		}
		if(flag)
		printf("LuckyChef\n");
		else
		printf("UnluckyChef\n");
	}
	return 0;
}
