#include<bits/stdc++.h>
using namespace std;

long long int a[100002];

int main()
{
	int t,n,i;
	long long int k,count,x,y,z,rem;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		
		count=0;  rem=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>rem)
			{
				x=a[i]-rem;
				y=x%k;   z=x/k;
				if(y!=0)
				{
					count+=z+1;
				    rem=k-y-1;
				}
				else
				{
					count+=z;
					rem=0;
				}
			}
			else if(a[i]<rem)
			{
				rem=rem-a[i]-1;
			}
			else if(a[i]==rem)
			{
				rem=rem-a[i];
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}
