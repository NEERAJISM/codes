#include<bits/stdc++.h>
using namespace std;
void bubble(vector <int> a, int n)
{
	int t,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j+1]<a[j])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	cout<<"bubble sorted sequence is \n";
	for(i=0;i<n;i++)
{
	cout<<a[i]<<"\t";}
		cout<<"\n";
}

void insertion(vector <int> a,int n)
{
	int t,i,j;
	for(i=1;i<n;i++)
	{
		for(j=i;j>=0;j--)
		{
			if(a[j-1]>a[j])
			{
				t=a[j-1];
				a[j-1]=a[j];
				a[j]=t;
			}
		}
	}
	cout<<"insertion sorted sequence is \n";
	for(i=0;i<n;i++)
	cout<<a[i]<<"\t";
	cout<<"\n";
}

int main()
{
	vector <int> a;
		vector <int> ::iterator k;
	int n,i,m;
	cout<<"enter the size \n";
	cin>>n;
	cout<<"enter the elements \n";
		for(i=0;i<n;i++)
{
	cin>>m;
	a.push_back(m);}
	bubble(a,n);
		cout<<" the elements  are \n";
			for(i=0;i<n;i++)
{
	cout<<a[i]<<"\t";}
	insertion(a,n);
	return 0;
	
	
}












