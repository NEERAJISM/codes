#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int t,i;
	long long int a,b,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		
		x=gcd(a,b);
		while(x!=1)
		{
			while(b%x==0)
			{
				b=b/x;
			}
			x=gcd(x,b);
		}
		
				if(b!=1)
				printf("No\n");
				else
				printf("Yes\n");
	}
	return 0;
}
