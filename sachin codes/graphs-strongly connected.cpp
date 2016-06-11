#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000

vector<vector<int> > g(maxn);
vector<vector<int> > g_rev(maxn);
vector<int> order; //  it is actually topological order
vector<int> comp;
vector<bool> visited(maxn);

void dfs1(int start)
{
	int v=start;
	visited[v]=true;
	for(int i=0;i<g[start].size();i++)
	{
		int neigh=g[start][i];
		if(!visited[neigh])
		dfs1(neigh);
	}
	order.push_back(v);
}
void dfs2(int start)
{
	int v=start;
	visited[v]=true;
	comp.push_back(v);
	for(int i=0;i<g[start].size();i++)
	{
		int neigh=g[start][i];
		if(!visited[neigh])
		dfs2(neigh);
	}

}
int main()
{
	int i,u,v,n,m,t,count=0;
	scanf("%d%d",&n,&m);
	g.resize(n+1);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g_rev[v].push_back(u);
	}
	
	for(i=1;i<=n;i++)
	visited[i]=false;
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			dfs1(i);
		}
	}
	
	for(i=1;i<=n;i++)
	visited[i]=false;
	for(i=1;i<=n;i++)
	{
		int v=order[n-i];
		if(!visited[v])
		{
			dfs2(v);
			count++;
			comp.clear();
		}
	}
	cout<<"count="<<count<<endl;
	
	return 0;
}
