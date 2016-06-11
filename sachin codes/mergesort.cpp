#include<stdio.h>
#include<iostream>
using namespace std;

int a[100000],b[100000];
void mergesort(int low,int mid,int high)
{
	int i=low,j=mid+1,k=low;
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
	for(i=low;i<=high;i++)
	a[i]=b[i];

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
	int i,n;
	printf("enter the size\n");
	scanf("%d",&n);
	printf("enter the array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	part(0,n-1);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
