#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

long long mulmod(long long int a,long long int b,long long int c)
{
	long long int x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x+y)%c;
		}
		y=(y+y)%c;
		b=b/2;
	}
	return x%c;
}

long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=mulmod(x,y,c);     //  or call  mulmod(x,y,c);
		}
		y=mulmod(y,y,c);          //  or call  mulmod(y,y,c);
		b=b/2;
	}
	return x%c;
}
long long int minimum(long long int y,long long int z)
{
	if(y<z)
	return y;
	return z;
}

int main()
{
	int t,n,i,j,k,pos1,pos2;
	long long int arr[1003],x,y,z,min,max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int b1[1003]={0};
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		max=0;
	
		for(i=0;i<n;i++)
		{
			min=1000000009;
		    for(j=0;j<n;j++)
		    {
		    	if(b1[j]==0&&b1[i]==0&&i!=j)
		    	{
		    			y=modular_exponentiation(arr[i],arr[j],1000000007);
		    			z=modular_exponentiation(arr[j],arr[i],1000000007);
		    			x=minimum(y,z);
		    			if(x<=min)
		    			{
		    				min=x;
		    				pos1=i;
		    				pos2=j;
		    			}
		    	}
		       
		    }
		     
		    
		    b1[pos1]++;
		    b1[pos2]++;
		    if(min!=1000000009)
		    {
		    	if(min>max)
		    	max=min;
		    }
		}
		printf("%lld\n",max);
	}
	return 0;
}
