#include<iostream>
#include<stdio.h>
using namespace std;

int a[1000000],b[1000000];
int mergesort(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=0;
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j])
		b[k++]=a[i++];
		else
		b[k++]=a[j++];
	}
	while(i<=mid)
	{
		b[k++]=a[i++];
	}
	while(j<=high)
	{
		b[k++]=a[j++];
	}
	k--;
	while(k>=0)
	{
		a[low+k]=b[k];
		k--;
	}
}

void part(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+mid)/2;
		part(a,low,mid);
		part(a,mid+1,high);
		mergesort(a,low,mid,high);
	}

}

int main()
{
	int i,n;
	cout<<"enter the size\n";
	scanf("%d",&n);
	cout<<"enter the array\n";
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	part(a,0,n-1);
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	printf("\n");
}
