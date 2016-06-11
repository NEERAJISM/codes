#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,c;
	long long int s,p,s1,y,z,x,n,k,i,a[100002];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<k;i++)
		scanf("%lld",&a[i]);
		
		sort(a,a+k);
		if(a[0]==1)
		printf("Chef\n");
		else if(a[0]==2)
		printf("Mom\n");
		else
		{
			s1=n*(n+1)/2;
		s=0;
		c=0;
		for(i=0;i<k;i++)
		{
			p=a[i]*(a[i]-1)/2;
			y=a[i];
			z=p-s;
			if(z<y)
			{
				x=a[i];
				c++;
				break;
			}
			s+=a[i];
		}
		if(c==0)
		{
			s1=s1-s;
			if(s1%2==0)
			printf("Chef\n");
			else
			printf("Mom\n");
		}
		else
		{
			if(x%2==0)
			printf("Mom\n");
			else
			printf("Chef\n");
		}
		}
		
		
	}
	return 0;
}
