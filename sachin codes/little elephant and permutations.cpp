#include<iostream>
#include<stdio.h>
using namespace std;
int a[102];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,c1=0,c2=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		for(i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			c1++;
		}
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(a[i]>a[j])
				c2++;
			}
		}
		if(c1==c2)
		printf("YES\n");
		else
		printf("NO\n");
		
	}
	return 0;
}
