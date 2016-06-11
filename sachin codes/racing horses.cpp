#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,a[5000],i;
	scanf("%d",&t);
	while(t--)
	{
	    int min,diff;   
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		
		min=a[n-1];
		for(i=0;i<n-1;i++)
		{
			diff=a[i+1]-a[i];
			if(diff<min)
			min=diff;
		}
		printf("%d\n",min);
	}
	return 0;
}
