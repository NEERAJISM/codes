#include<iostream>
using namespace std;


int find_index(int a[],int start,int end)
{
	int pivot=a[end];
	int idx=start;
	for(int i=start;i<end;i++)
	{
		if(a[i]<pivot)
		{
			int t=a[i];
			a[i]=a[idx];
			a[idx]=t;
			idx++;
		}
	}
	int t=a[end];
	a[end]=a[idx];
	a[idx]=t;
	return idx;
}

int find_kth(int a[],int k,int l,int r)
{
		int idx=find_index(a,l,r);   //cout<<"idx="<<idx<<endl;
		if(idx==k-1)
		return a[idx];
		else if(idx<k-1)
		{
			return find_kth(a,k,idx+1,r);
		}
		else
		{
			return find_kth(a,k,l,idx-1);
		}
	
}



int main()
{
	int a[100000],i,n,k;
	cout<<"enter the size\n";;
	cin>>n;
	cout<<"enter the array\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<"enter k=";
	cin>>k;
	int ans=find_kth(a,k,0,n-1);
	
	cout<<"ans="<<ans;
	return 0;
}
