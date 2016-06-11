#include<iostream>
#include<stdio.h>
using namespace std;
int c[100002],d[100002];
int a[100002],b[100002];
 
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
		else if(a[i]>a[j])
		{
		    b[k++]=a[j++];
		    d[k2++]=c[j2++];
        }
        else if(a[i]==a[j])
        {
        	if(c[i]>c[j])
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
	k--;k2--;
	while(k>=0)
	{
		a[low+k]=b[k];
		c[low+k2]=d[k2];
		k--;k2--;
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
	int t,n,i,count,j,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i],&c[i]);
		}
		
		part(0,n-1);
	/*	for(i=0;i<n;i++)
		{
			cout<<a[i]<<","<<c[i];
			cout<<"\n";
		}
	    cout<<"ffgg\n";*/	
		i=0;count=0;
		while(i<n)
		{
			x=c[i];
			j=1;
			while(a[i+j]<=x&&a[i+j]<=c[i+j-1]&&i+j<n)
			{
				if(c[i+j]<x)
				x=c[i+j];
				j++;
			}
			count++;
			i=i+j;
		}
		printf("%d\n",count);
	}
	return 0;
}
