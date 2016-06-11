#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i;
	long long int n,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&s);
		long long int m=n;
		long long int c=0;n=1;
		s=s-m;
		while(s-n>=0&&n!=m)
	    {
	    	s=s-n;
	    	n++;
	    	c++;
	    }
	    ++c;
	    printf("%lld\n",m-c);
	}
	return 0;
}
