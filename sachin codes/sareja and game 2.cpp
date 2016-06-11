#include<bits/stdc++.h>
using namespace std;
 
double a[15];
double b[15][10003];
double mark[15];
 
int main()
{
	int t,n,m,i,j;
	double x,sum,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			a[i]=0;
			mark[i]=0;
		}
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lf",&b[i][j]);
			}
		}
		
 		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(b[i][j]==0)
				{
					mark[i]=1;
					break;
				}
				else
				{
					x=log10(b[i][j]);
					a[i]+=x;
				}
			}
		}
		
		int count=0;
		for(i=1;i<=n;i++)
		{
			if(mark[i]==1)
			count++;
		}
		
		if(count==n)
		ans=0;
		else if(mark[1]==1)
		ans=0;
		else
		{
			x=a[1];
			for(i=1;i<=n;i++)
			{//cout<<a[i]<<"  ";
				if(mark[i]==0)
				{
					a[i]=a[i]-x;
					//cout<<"i="<<i<<"   "<<a[i]<<endl;
				}
			}
			
			sum=0;
			for(i=1;i<=n;i++)
			{
				if(mark[i]==0)
				{
					x=pow(10,a[i]);
					sum+=x;
				}
			}
			
			ans=1/sum;
		}

		printf("%.6lf\n",ans);
	}
	return 0;
} 
