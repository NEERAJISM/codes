#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,m,max,min;
	int s,n,i,j,d,e;
	scanf("%d",&t);
	while(t--)
	{
		int a[100002]={0},b[100002];
		scanf("%d%d",&n,&m);
		
		for(i=0;i<m;i++)
		scanf("%d",&b[i]);
		if(n==1)
		printf("0\n");
		else
		{
		 max=b[0];min=b[0];
		for(i=0;i<m;i++)
		{
			if(b[i]>max)
			max=b[i];
			if(b[i]<min)
			min=b[i];
		}
	
		if(max!=min)
		{
		     for(i=0;i<=min;i++)
		     {
		     	a[i]=max-i;
		     }
		     for(i=n-1;i>=max;i--)
		     {
		     	a[i]=i-min;
		     }
		     for(i=min+1;i<max;i++)
		     {
		     	d=i-min;
		     	e=max-i;
		     	a[i]=d>e?d:e;;
		     }
		 }
		 else
		 {
		 	for(i=0;i<n;i++)
		 	{
		 		d=min-i;
		 		if(d<0)
		 		d=-d;
		 		a[i]=d;
		 	}
		 }
		     
		for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");}
	}
	return 0;
}
