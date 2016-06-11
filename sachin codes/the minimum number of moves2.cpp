#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i,count,min;
	scanf("%d",&t);
	while(t--)
	{
		int a[102]={0};
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		min=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]<min)
			min=a[i];
		}
		count=0;
        for(i=0;i<n;i++)
        {
        	count+=(a[i]-min);
        }
		printf("%d\n",count);
	}
	return 0;
}
