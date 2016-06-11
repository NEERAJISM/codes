#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,m,i,j,k,a[1000],b[1000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
		}
		if(m==0)
		b[0]=0;
		sort(b,b+m);
		i=1;j=0;k=0;
		while(i<=n)
		{
			if(i!=b[j])
			{
				a[k]=i;
				i++;
				k++;
			}
			else
			{
				i++;
				j++;
			}
			
		}
	    for(i=0;i<n-m;i=i+2)
		{
			cout<<a[i]<<" ";
			
		}
		cout<<"\n";
		for(i=1;i<n-m;i=i+2)
		{
			cout<<a[i]<<" ";
			
		}
		cout<<"\n";
		
	
	}
	return 0;
}
