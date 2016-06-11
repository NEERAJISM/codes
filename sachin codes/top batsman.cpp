#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int b[12];
int main()
{
	int t,a[11],i,k,j;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<11;i++)
		scanf("%d",&a[i]);
		scanf("%d",&k);
		sort(a,a+11);
		int c[k];
		i=0;
		while(i<k)
		{
			c[i]=a[11-1-i];i++;
		}
		for(i=0;i<k;i++)
		{
			for(j=0;j<11;j++)
			{
				if(c[i]==a[j])
				b[i]++;
			}
		}
		int s=0;
		for(i=0;i<12;i++)
		{
			if(b[i]>1)
			s+=b[i];
		}
		printf("%d\n",s+1);
	}
	return 0;
}
