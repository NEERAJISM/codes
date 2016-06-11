#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,c,c1,s,n,a[10002],i,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		c=0;
		for(i=0;i<n;i++)
		if(a[i]>100)
		c++;
		
		if(c!=0)
		printf("NO\n");
		else
		{
		
			s=0;count=0;
			for(i=0;i<n;i++)
			{
				s+=a[i];
				if(a[i]==0)
				count++;
			}
			if(s<100)
			printf("NO\n");
			else if(s-100>n-1-count)
			printf("NO\n");
			else
			printf("YES\n");
	    }
	}
	return 0;
}
