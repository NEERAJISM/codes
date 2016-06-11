#include<bits/stdc++.h>
using namespace std;

long long int a[1000002];
int main()
{
	long long int n,m,i;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	
	long long int max=a[0],max2=a[0],first=0;
	
	for(i=1;i<n;i++)
	{
		max=max+a[i];
		while(max>m)
		{
			max=max-a[first];
			first++;
		}
		if(max>max2)
		max2=max;
	}
	
	printf("%lld\n",max2);
}
