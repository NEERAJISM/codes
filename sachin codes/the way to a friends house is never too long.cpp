#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int x[100000],y[100000],b[100000],d[100000];
int mergesort(int low,int mid,int high)
{
	int i=low,j=mid+1,k=0,i2=low,j2=mid+1,k2=0;
	while(i<=mid&&j<=high)
	{
		if(x[i]<x[j])
		{
		    b[k++]=x[i++];
		    d[k2++]=y[i2++];
	    }
		else if(x[i]>x[j])
		{
		    b[k++]=x[j++];
		    d[k2++]=y[j2++];
        }
        else if(x[i]==x[j]&&y[i]>y[j])
        {
        	b[k++]=x[i++];
        	d[k2++]=y[i2++];
        }
        else if(x[i]==x[j]&&y[i]<y[j])
        {
        	b[k++]=x[j++];
        	d[k2++]=y[j2++];
        }
    }
	while(i<=mid)
	{
		b[k++]=x[i++];
		d[k2++]=y[i2++];
	}
	while(j<=high)
	{
		b[k++]=x[j++];
		d[k2++]=y[j2++];
	}
	k--;k2--;
	while(k>=0)
	{
		x[low+k]=b[k];
		y[low+k2]=d[k2];
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
	int t,n,i,s=0;
	
	scanf("%d",&t);
	while(t--)
	{
		double d=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
		part(0,n-1);
                                                                        
		for(i=0;i<n-1;i++)
		{
			s=(y[i+1]-y[i])*(y[i+1]-y[i])+(x[i+1]-x[i])*(x[i+1]-x[i]);
			d+=sqrt(s);
		}
		printf("%.02lf\n",d);
	}
	return 0;
}
