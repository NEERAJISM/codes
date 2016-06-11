#include<bits/stdc++.h>
using namespace std;

map<long long int ,long long int> m;
map<long long int ,long long int> :: iterator it;

long long int func(long long int n)
{
	if(n==0)
	return n;
	
	it=m.find(n);
	if(it!=m.end())
	return m[n];
	else
	{
		long long int x,y,z;
		
		x=func(n/2);
		y=func(n/3);
		z=func(n/4);
		
		if(x+y+z>n)
		{
			m[n]=x+y+z;
			return m[n];
		}
		else
		{
			m[n]=n;
			return m[n];
		}
	}
}

int main()
{
	int i,j,t;
	long long int n,x;
	while(scanf("%lld",&n)!=EOF)
	{
		m.clear();
		x=func(n);
		printf("%lld\n",x);
	}
	return 0;
}
