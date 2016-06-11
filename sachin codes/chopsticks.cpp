#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100002];
int main()
{
	int d,n,i,count;
	scanf("%d%d",&n,&d);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	count=0;
	for(i=0;i<n-1;)
	{
		if(a[i+1]-a[i]<=d)
		{
			count++;
			i=i+2;
		}
		else
		i++;
	}
	printf("%d\n",count);
	return 0;
}
