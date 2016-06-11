#include<iostream>
#include<stdio.h>
using namespace std;
char c[100000],d[100000];
int a[100000],b[100000];

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
	int t,n,m,i;
	scanf("%d",&t);
	while(t--)
	{
		long long int sum=1;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			cin>>c[i]>>a[i];
		}
		part(0,m-1);
	    if(m==1)
		printf("1\n");
		else
		{
		                                                                                                     
		    for(i=0;i<m-1;i++)
		    {   
			    if(int(c[i]-c[i+1])!=0)
			    sum*=(a[i+1]-a[i]);
			    sum=sum%1000000009;
		    }
            
            sum=sum%1000000009;
		    printf("%lld\n",sum);
	    }
	}
	return 0;
}
