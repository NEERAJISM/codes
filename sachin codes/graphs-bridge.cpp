#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000

vector<vector<int> > g;
vector<bool> visited(maxn);
vector<int> time_in(maxn);
vector<int> dbe(maxn);
vector<pair<int,int> >store_bridge;
int timer=0;


void bridge(int start,int parent=-1)
{
	int v=start;
	visited[v]=true;
	time_in[v]=dbe[v]=timer++;
	
	for(int i=0;i<g[v].size();i++)
	{
		int neigh=g[v][i];
		
		if(neigh==parent)
		continue;
		
		if(visited[neigh])
		dbe[v]=min(dbe[v],time_in[neigh]);
		else
		{
			bridge(neigh,v);
			dbe[v]=min(dbe[v],dbe[neigh]);
			if(dbe[v]>=time_in[v]&&parent!=-1)
			{
				store_bridge.push_back(make_pair(v,parent));  // first one will always come as bridge(1--(-1))
			}
		}
	}
}




int main()
{
/*	g.clear();
	colour.clear();
	time_in.clear();
	time_out.clear();
	*/
	int i,u,v,n,m,t;
	scanf("%d%d",&n,&m);
	g.resize(n+1);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	visited[i]=false;
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		bridge(i);
	}
	for(i=0;i<store_bridge.size();i++) 
	cout<<store_bridge[i].first<<" -- "<<store_bridge[i].second<<endl;
	return 0;
}
