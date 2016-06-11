#include<bits/stdc++.h>
using namespace std;

int a[40];

int binary(int n,int x)
{
	int low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
		return mid;
		else if(a[mid]>x)
		high=mid-1;
		else if(a[mid]<x)
		low=mid+1;
	}
	return -1;
}

int lower(int n,int x)
{
	int low=0,high=n-1,mid,res=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
		{
			res=mid;
			high=mid-1;
		}
		else if(a[mid]>x)
		high=mid-1;
		else if(a[mid]<x)
		low=mid+1;
	}
	return res;
}

int upper(int n,int x)
{
	int low=0,high=n-1,mid,res=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
		{
			res=mid;
			low=mid+1;
		}
		else if(a[mid]>x)
		high=mid-1;
		else if(a[mid]<x)
		low=mid+1;
	}
	return res;
}

int main()
{
	int i,n,x;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	
	cin>>x;
	cout<<"lower="<<lower(n,x)<<endl<<"upper="<<upper(n,x)<<endl;
	return 0;
}
