#include<iostream>
#include<stdio.h>
using namespace std;
int a[100000];

void sorting(int n)
{
	
	int t,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j+1]<a[j])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sorting(n);
	for(int i=0;i<n;i++)
	cout<<a[i];
	
}
