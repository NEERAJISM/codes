#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,i,count;
	long long int m,a[10],s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&m);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		sort(a,a+n);
		s=0;count=0;
		for(i=n-1;i>=0;i--)
		{
			s+=a[i];
			count++;
			if(s>=m)
			break;
		}
		if(s<m)
		printf("-1\n");
		else
		printf("%d\n",count);
	}
	return 0;
}
