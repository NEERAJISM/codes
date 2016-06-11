#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	long long int s,n;
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		scanf("%lld",&n);
		s=(n*(n+1))/2;
        s+=n;
	    cout<<s<<endl;
	}
	return 0;
}
