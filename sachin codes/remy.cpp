#include<iostream>
#include<stdio.h>
using namespace std;
int a[100001];
int main()
{
	int t;
	int n,m,i,j,k,y,z,x;
		char c;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<m;i++)
		{
			cin>>c>>x;
			a[x]=int(c);
		}
		long long int s=1;
		for(k=1;k<100001;k++)
		{
			if(a[k]!=0)
			{
				y=a[k];
				i=k;
				break;
			}
		}
		z=i;
		for(j=i+1;j<100001;j++)
		{
			if(a[j]!=0)
			{
				if(a[j]-y!=0)
				{
					s=s*(j-z);
				    s=s%1000000009;
				}
			    
				y=a[j];
				z=j;
			}
			
		}
		s=s%1000000009;
		cout<<s<<"\n";
		
	}
	return 0;
}
