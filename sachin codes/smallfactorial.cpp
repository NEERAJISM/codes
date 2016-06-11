#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int l,t,a[200];
	
	scanf("%d",&t);
	while(t--)
	{
		int n,k,j,x,m=1,i=1,temp=0;
		scanf("%d",&n);
		for(l=0;l<200;l++)
	{
		a[l]=1;
	}
		
		while(i<=n)
		{
			for(j=1;j<=m;j++)
		{
			x=(a[j]*i)+temp;
			a[j]=x%10;
			temp=x/10;
		}
			k=1;
			while(temp!=0)
			{
				a[j+k-1]=temp%10;
				temp=temp/10;
				k++;
				m++;
			}
			
		
		i++;
	    }
		for(j=m;j>=1;j--)
		{
			cout<<a[j];
		}
		cout<<"\n";
	}
	return 0;
}
