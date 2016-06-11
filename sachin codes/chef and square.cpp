#include<iostream>
#include<stdio.h>
using namespace std;
long long int x[2001],y[2001],A1[2001],B1[2001],A2[2001],B2[2001],A3[2001],B3[2001];
int a[2001][20001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,k;
		double m1,m2,m3;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
		int I=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					m1=(y[j]-y[i])/(x[j]-x[i]);
					m2=(y[k]-y[j])/(x[k]-x[j]);
					m3=(y[k]-y[i])/(x[k]-x[i]);
					if(m1*m2==-1)
					{
						if(a[i][j]==0)a[i][j]++;
						A1[I]=x[i];B1[I]=y[i];
						A2[I]=x[j];B2[I]=y[j];
						A3[I]=x[k];B3[I]=y[k];
						I++;
					}
					if(m1*m3==-1)
					{
						
					}
				}
			}
		}
		int count=0,count1=0,count2=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]==0)
				count++;
				else if(a[i][j]==1)
				count1++;
				else if(a[i][j]==2)
				count2++;
			}
		}
		if(count1>=1&&count2==0)
		printf("1\n");
		if(count==n*n)
		printf("2\n");
		
	}
}
