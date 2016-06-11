#include<iostream>
#include<stdio.h>
using namespace std;



int gcd(int p,int q)
{
	if(q==0)
    return p;
	else
	return gcd(q,p%q);
}


int main()
{
	int t,n,i,max,y,x,q,l,XX,YY,ZZ,r;
	scanf("%d",&t);
	while(t--)
	{
		int a[100002],b[100002],c[100002];
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
		x=a[1];
		for(i=1;i<=n;i++)
		{
			x=gcd(x,a[i]);
			b[i]=x;
		}
		y=a[n];
		for(i=n;i>=1;i--)
		{
			y=gcd(y,a[i]);
			c[i]=y;
		}
		while(q--)
		{
			scanf("%d%d",&l,&r);
			if(l==1)
			printf("%d\n",c[r+1]);
			else if(r==n)
			printf("%d\n",b[l-1]);
			else
			{
				XX=b[l-1];
			YY=c[r+1];
			ZZ=gcd(XX,YY);
			printf("%d\n",ZZ);
			}
			
		}
	}
	return 0;
}
