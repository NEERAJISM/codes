#include<iostream>
#include<stdio.h>
using namespace std;
int a[1000],b[1000],c[1000],d[1000];
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		scanf("%d",&c[i]);
		part(0,n-1);

		
		int max=0,count;
		for(i=0;i<n-1;i++)
		{
	        count=0;
			for(j=i;j<n;j++)
			{
				if(c[i]>a[j])
				{
					count++;
				}
				else
				break;
			}
			if(count>max)
			max=count;
		}
		printf("%d\n",max);
	}
	return 0;
}
