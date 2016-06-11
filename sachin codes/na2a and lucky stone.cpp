#include<bits/stdc++.h>
using namespace std;

long long int a[100002];
int main()
{
	int n,i,count,count1,count2,y;
	long long int x,z;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	
	for(i=0;i<n;i++)
	{
		x=a[i];  count1=0;
		while(x%5==0)
		{
			x=x/5;
			count1++;
		}
		x=a[i];  count2=0;
		while(x%10==0)
		{
			x=x/10;
			count2++;
		}
		count=count1-count2;
		
		y=(count+1)/2;
		
		z= a[i]*pow(4,y);
		
		printf("%lld\n",z);
	}
	return 0;
}
