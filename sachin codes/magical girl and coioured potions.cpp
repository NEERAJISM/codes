#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long int r[100],g[100],b[100];

int maximum(int R,int G,int B)
{
	int maxr=r[R-1],maxg=g[G-1],maxb=b[B-1];
	
	
	if((maxr>=maxg)&&(maxr>=maxb))
	return 1;
	if((maxg>=maxr)&&(maxg>=maxb))
	return 2;
	if((maxb>=maxr)&&(maxb>=maxg))
	return 3;
	
}
void change(int R,int G,int B,int maxi)
{
	int i;
	if(maxi==1)
	{
	    for(i=0;i<R;i++)
	    r[i]=r[i]/2;
	}
		if(maxi==2)
	{
	    for(i=0;i<G;i++)
	    g[i]=g[i]/2;
	}
		if(maxi==3)
	{
	    for(i=0;i<B;i++)
	    b[i]=b[i]/2;
	}
}
int main()
{
	int t,R,G,B,n;
	scanf("%d",&t);
	while(t--)
	{
		int j;
		scanf("%d%d%d%d",&R,&G,&B,&n);
		for(j=0;j<R;j++)
		scanf("%d",&r[j]);
		for(j=0;j<G;j++)
		scanf("%d",&g[j]);
		for(j=0;j<B;j++)
		scanf("%d",&b[j]);
		
		sort(r,r+R);
		sort(g,g+G);
		sort(b,b+B);
		int maxi;
		long long int max=0,m;
		j=1;
		while(j<=n)
		{
			maxi=maximum(R,G,B);
			if(maxi==1)
			m=r[R-1];
			else if(maxi==2)
			m=g[G-1];
			else if(maxi==3)
			m=b[B-1];
	
			if(j==1)
			max=m;
			else if(j!=1&&m<max)
			max=m;
			change(R,G,B,maxi);
			j++;
		}
		maxi=maximum(R,G,B);
			if(maxi==1)
			m=r[R-1];
			else if(maxi==2)
			m=g[G-1];
			else if(maxi==3)
			m=b[B-1];
	
			if(m<max)
			max=m;
		printf("%d\n",max);
	}
	return 0;
}
