#include<iostream>
#include<stdio.h>
using namespace std;
int d[100002],a[100002],c[100002];
int b[100002];
 
int mergesort(int low,int mid,int high)
{
	int i=low,j=mid+1,k=0,i2=low,j2=mid+1,k2=0;
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j])
		{
		    b[k++]=a[i++];
		    d[k2++]=c[i2++];
	    }
		else
		{
		    b[k++]=a[j++];
		    d[k2++]=c[j2++];
        }
    }
	while(i<=mid)
	{
		b[k++]=a[i++];
		d[k2++]=c[i2++];
	}
	while(j<=high)
	{
		b[k++]=a[j++];
		d[k2++]=c[j2++];
    }
 
}
 
void part(int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		part(low,mid);
		part(mid+1,high);
		mergesort(low,mid,high);
	}
 
}
 

int main()
{
	int n,x,y,i,j,s1=0,s2=0;
	long long int sum=0;
	scanf("%d%d%d",&n,&x,&y);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	scanf("%d",&c[i]);
	
	part(0,n-1);
	for(i=n-1;i>=0;i--)
	{
		if(b[i]>d[i])
		{
			if(s1<x)
			{
				s1++;
				sum+=b[i];
			}
			else
			{
				s2++;
				sum+=d[i];
			}
		}
		else
		{
			if(s2<y)
			{
				s2++;
				sum+=d[i];
			}
			else
			{
				s1++;
				sum+=b[i];
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}
