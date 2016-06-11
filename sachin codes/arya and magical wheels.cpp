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
	int t,n,i,j,x;
	long long int a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		long long int c=a*b;
		long long int d=gcd(a,b);
		long long int e=c/d;
		long long int ans=e/b;
		printf("%lld\n",ans);
	}
}
