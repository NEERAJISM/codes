#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int a[101][101]={3},i,j,r[100001],c[100001],x[100001],y[100001];
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&r[i],&c[i]);
		a[r[i]-1][c[i]-1]=2;
	}
	int count=0,val=0;
	for(i=0;i<n;i++)
	{
		j=0;
		while(j!=m)
		{
		if(a[i][j]!=2)
		{
			x[val]=i;
			y[val]=j;
			val++;
			while(a[i][j]!=2&&j<m)
			{
				
				j++;
			}
			
		}
		else
			j++;
		}
	}
	printf("%d\n",val);
	for(i=0;i<val;i++)
	{
		printf("%d %d 0\n",(x[i]+1),(y[i]+1));
	}
	return 0;
}
