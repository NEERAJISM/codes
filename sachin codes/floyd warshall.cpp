#include<bits/stdc++.h>
using namespace std;
#define maxn 10

int a[maxn][maxn];
int d[maxn][maxn];
int pi[maxn][maxn];

int main()
{
	int n,i,j;
	cin>>n;
	
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	cin>>a[i][j];
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]!=0)
			{
				d[i][j]=a[i][j];
				pi[i][j]=i;
			}
			else
			{
				d[i][j]=10000;
				pi[i][j]=0;
			}
		}
	}

	for(int k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(d[i][j]>d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					pi[i][j]=pi[k][j];
				}
			}
		}
	}

	cout<<"shortest paths\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<d[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<"parents\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<pi[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	cout<<"enter the starting and ending vertices\n";
	int x,y;
	cin>>x>>y;
	cout<<"the path is= ";
	while(y!=x)
	{
		cout<<y<<"  ";
		y=pi[x][y];
	}
	cout<<x<<"  ";
	
	return 0;
}
