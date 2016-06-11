#include<iostream>
#include<stdio.h>
using namespace std;
int B[1002],C[1002],D;

int  f(int a[],int n,int k)
{
	int min=a[0],max=a[0],pmin=0,pmax=0,c=0,diff,d,j,i;
	for(i=0;i<n;i++)
	{
		    if(a[i]<min)
	     	{
		     	min=a[i];
			    pmin=i;
	    	}
	    	if(a[i]>max)
	     	{
		    	max=a[i];
		     	pmax=i;
	     	}
    }
     	diff=max-min;
	for(j=0;j<k;j++)
	{
		a[pmin]++;B[j]=pmin+1;
		a[pmax]--;C[j]=pmax+1;
		c++;
		min=a[0];max=a[0];pmin=0;pmax=0;
	    for(i=0;i<n;i++)
	    {
		    if(a[i]<min)
	     	{
		     	min=a[i];
			    pmin=i;
	    	}
	    	if(a[i]>max)
	     	{
		    	max=a[i];
		     	pmax=i;
	     	}
     	}
		d=max-min;
		if(d<diff)
		diff=d;
		else if(d==diff)
		{
			
		
		}
		else if(d>diff)
		break;
   }
   D=diff;
   return c;
}
int main()
{
	int n,k,a[102],i,count=0,c;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	if(a[i]==a[0])
	count++;
	if(count==n)
	printf("0 0");
	else
	{
	
	c=f(a,n,k);
	printf("%d %d\n",D,c);
	for(i=0;i<c;i++)
	{
		printf("%d %d\n",C[i],B[i]);
	}}
	return 0;
}
