#include<iostream>
#include<stdio.h>
using namespace std;

void bubble(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

void selection(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int min_index=i;
		for(int j=i;j<n;j++)
		{
			if(a[j]<a[min_index])
			min_index=j;
		}
		int t=a[min_index];
		a[min_index]=a[i];
		a[i]=t;
	}
}

void insertion(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=a[i];
		int j=i-1;
		while(temp<a[j]&&j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}

int main()
{
	int a[100],n;
	cout<<"enter the size\n";
	cin>>n;
	cout<<"enter the elements\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	int c;
	cout<<"enter the algorithm you want to use    1=bubble   2=selection   3=insertion\n";
	cin>>c;
	if(c==1)
	bubble(a,n);
	else if(c==2)
	selection(a,n);
	else if(c==3)
	insertion(a,n);
	
	cout<<"sorted sequence is\n";
	for(int i=0;i<n;i++)
	cout<<a[i]<<"  ";
	cout<<endl;
	return 0;
}







