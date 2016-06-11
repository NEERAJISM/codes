#include<bits/stdc++.h>
using namespace std;
#define INF 1000000

vector<vector<pair<int,int> > > g;
vector<vector<pair<int,int> > > g_rev;
vector<int> d;
vector<int> d_rev;



void dijkstra1(int n,int start)
{
	priority_queue<pair<int,int> > pq;
	d[start]=0;
	pq.push(make_pair(0,start));
	
	while(!pq.empty())
	{
		int v=pq.top().second;   int curr_dis=-pq.top().first;
		pq.pop();
		
		if(curr_dis>d[v])
		continue;
		
		for(int j=0;j<g[v].size();j++)
		{
			int neigh=g[v][j].first;
			int len=g[v][j].second;
			
			if(d[v]+len<d[neigh])
			{
				d[neigh]=d[v]+len;
				pq.push(make_pair(-d[neigh],neigh));
			}
		}
	}
}

void dijkstra2(int n,int start)
{
	priority_queue<pair<int,int> > pq;
	d_rev[start]=0;
	pq.push(make_pair(0,start));
	
	while(!pq.empty())
	{
		int v=pq.top().second;   int curr_dis=-pq.top().first;
		pq.pop();
		
		if(curr_dis>d_rev[v])
		continue;
		
		for(int j=0;j<g_rev[v].size();j++)
		{
			int neigh=g_rev[v][j].first;
			int len=g_rev[v][j].second;
			
			if(d_rev[v]+len<d_rev[neigh])
			{
				d_rev[neigh]=d_rev[v]+len;
				pq.push(make_pair(-d_rev[neigh],neigh));
			}
		}
	}
}

int main()
{
	int n,m,start,dest,u,v,w,i,j,ans,shortest_dist;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
		break;
		
		g.clear();
		g_rev.clear();
		
		g.resize(n+1);
		g_rev.resize(n+1);
	    d.resize(n+1);
	    d_rev.resize(n+1);
		
		scanf("%d%d",&start,&dest);
		
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			//cout<<"helllo";
			g[u].push_back(make_pair(v,w));
			//cout<<"hi";
			g_rev[v].push_back(make_pair(u,w));
			//cout<<"llllo";
		}
		
		for(i=0;i<=n;i++)
		d[i]=INF;
		
		dijkstra1(n,start);
		shortest_dist=d[dest];
		
		for(i=0;i<=n;i++)
		d_rev[i]=INF;
		
		dijkstra2(n,dest);
		
		for(i=0;i<n;i++)
		{
			int v=i;
			
			for(j=0;j<g[v].size();j++)
			{
				int neigh=g[v][j].first;
				int len=g[v][j].second;
				
				if(d[v]+len+d_rev[neigh]==shortest_dist)
				g[v].erase(g[v].begin()+j);
			}
		}
		
		for(i=0;i<=n;i++)
		d[i]=INF;
		
		dijkstra1(n,start);
		
		if(d[dest]==INF)
		ans=-1;
		else
		ans=d[dest];
		
		printf("%d\n",ans);
	}
	return 0;
}
