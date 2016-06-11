#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i,a[102][102],j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=0;
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		
		for(i=n-2;i>=0;i--)
		{
			for(j=n-2;j>=0;j--)
			{
				if(a[i+1][j]>a[i+1][j+1])
				a[i][j]+=a[i+1][j];
				else
				a[i][j]+=a[i+1][j+1];
			}
		}
		printf("%d\n",a[0][0]);
	}
	return 0;
}
