#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,p[30],r[30],i,j,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&p[i]);
		for(i=0;i<n;i++)
		scanf("%d",&r[i]);
		sort(p,p+n);
		sort(r,r+n);
		
		i=0;j=0;c=0;
		while(i<n&&j<n)
		{
			if(r[j]>=p[i])
			{
				c++;i++;j++;
			}
			else if(r[j]<p[i])
			{
				j++;
			}
		}
		printf("%d",c);
		printf("\n");
	}
	return 0;
}
