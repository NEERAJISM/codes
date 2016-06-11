#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
using namespace std;


long long int ncr(long long int v,long long int b)
{
	long long int r;
	r=min(b,v-b);//cout<<" asd";
	if(r==0||v==0)
	return 1;
	return ncr(v-1,r-1) * v / r;
}


int main()
{
	int t;
	long long int s,n,m,k,K,i,j,p,q,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&s,&n,&m,&k);
		p=0;
		x=min(m-1,n-1);
		q=ncr(s-1,n-1);
		 K = max(k, n-1 + m-s);
		for(i=K;i<=x;i++)
		{
			p+=(ncr(m-1,i)*ncr(s-m,n-i-1));
		}
		printf("%lld\n",(p/q));
	}
	return 0;
}
