#include<bits/stdc++.h>
using namespace std;
#define maxn 10000000

int n,T,total_cost,total_time;

int cost[52][52],times[52][52],visited[52];

void dfs(int ver,int c,int t)
{
	if(c>total_cost)
	return ;
	if(t>T)
	return ;
	if(ver==n)
	{
		if(c<total_cost)
		{
			total_cost=c;
			total_time=t;
		}
		else if(c==total_cost&&t<total_time)
		total_time=t;
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=ver)
			{
				if(visited[i]==0)
				{
					visited[i]=1;
					dfs(i,c+cost[ver][i],t+times[ver][i]);
					visited[i]=0;
				}
			}
		}
    }
}

int main()
{
	int i,j;
	scanf("%d%d",&n,&T);
	while(n!=0)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&times[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&cost[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		visited[i]=0;
		
		visited[1]=1;
		
		total_cost=maxn; total_time=maxn;
		
		dfs(1,0,0);
		
		printf("%d %d\n",total_cost,total_time);
		
		scanf("%d%d",&n,&T);
	}
	return 0;
}
