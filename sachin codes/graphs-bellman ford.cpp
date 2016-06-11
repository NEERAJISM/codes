#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define inf 1000000000

vector<vector<pair<int,int> > > g(maxn); 
vector<int> d(maxn,inf); 

void bellman_ford(int n,int start)
{
	d[start]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int k=1;k<=n;k++)
		{
			int v=k;
			for(int j=0;j<g[v].size();j++)
			{
				int neigh=g[v][j].first;
				int length=g[v][j].second;
				d[v]=min(d[v],d[neigh]+length);//cout<<d[v]<<endl;
			}
		}
	}
}

int main()
{
	int u,v,w,i,n,m,source,sink;
    cin>>n>>m;
    g.resize(n+1);
	while(m--)
	{
		cin>>u>>v>>w;
		g[v].push_back(make_pair(u,w));//instead of g[u].pb(u,w) because we work with in-adjacent neighbours not out-adjacent
	}	
	cout<<"enter the source and sink vertex\n";
	cin>>source>>sink;
	bellman_ford(n,source);
	cout<<"least distance = "<<d[sink];
	return 0;
}
