#include<iostream>
using namespace std;

int part(int a[],int start,int end)
{
	int t,i;
	int pivot = a[end];
	int pivot_index=start;
	for(i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			t=a[i];
			a[i]=a[pivot_index];
			a[pivot_index]=t;
			pivot_index++;
		}
	}
	t=a[pivot_index];
	a[pivot_index]=a[end];
	a[end]=t;
	
	return pivot_index;
}

void quicksort(int a[],int start,int end)
{
	if(start<end)
	{
		int pivot_index=part(a,start,end);
		quicksort(a,start,pivot_index-1);
		quicksort(a,pivot_index+1,end);
	}

}

int main()
{
	int a[100000],i,n;
	cout<<"enter the size\n";;
	cin>>n;
	cout<<"enter the array\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
	cout<<a[i]<<"\t";
}
