#include<iostream>
#include<stdio.h>
using namespace std;
int row[314160],col[314160];
char c[10];
int main()
{
	int n,q,i,r,x;
	long long int maxr=0,maxc=0;
	scanf("%d%d",&n,&q);
	for(i=0;i<q;i++)
	{
		cin>>c>>r>>x;
	    //printf("%d%d",&r,&x);
		if(c[0]=='R')
		row[r]+=x;
		else
		col[r]+=x;
	}
	for(i=0;i<n+1;i++)
	{
		if(row[i]>maxr)
		maxr=row[i];
		if(col[i]>maxc)
		maxc=col[i];
	}

	printf("%lld\n",maxr+maxc);
	return 0;
}
