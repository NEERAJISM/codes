#include<bits/stdc++.h>
using namespace std;
#define INF 1061109567

vector<vector<pair<int,long long int> > > g;
vector<vector<pair<int,long long int> > > g_rev;
vector<long long int> d;
vector<long long int> d_rev;
vector<pair<int,pair<int,long long int> > > edge_list;



void dijkstra1(int n,int start)
{
	priority_queue<pair<long long int,int> > pq;
	d[start]=0;
	pq.push(make_pair(0,start));
	
	while(!pq.empty())
	{
		int v=pq.top().second;   long long int curr_dis=-pq.top().first;
		pq.pop();
		
		if(curr_dis>d[v])
		continue;
		
		for(int j=0;j<g[v].size();j++)
		{
			int neigh=g[v][j].first;
			long long int len=g[v][j].second;
			
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
	priority_queue<pair<long long int,int> > pq;
	d_rev[start]=0;
	pq.push(make_pair(0,start));
	
	while(!pq.empty())
	{
		int v=pq.top().second;   long long int curr_dis=-pq.top().first;
		pq.pop();
		
		if(curr_dis>d_rev[v])
		continue;
		
		for(int j=0;j<g_rev[v].size();j++)
		{
			int neigh=g_rev[v][j].first;
			long long int len=g_rev[v][j].second;
			
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
	int n,m,start,dest,t,k,i,j,u,v;
	long long int w,ans,shortest_dist;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&m,&k,&start,&dest);
		
		g.clear();
		g_rev.clear();
		edge_list.clear();
		
		g.resize(n+1);
		g_rev.resize(n+1);
	    d.resize(n+1);
	    d_rev.resize(n+1);
	   // edge_list.resize(k+1);
		
		while(m--)
		{
			scanf("%d%d%lld",&u,&v,&w);
			//cout<<"helllo";
			g[u].push_back(make_pair(v,w));
			//cout<<"hi";
			g_rev[v].push_back(make_pair(u,w));
			//cout<<"llllo";
		}
		for(i=0;i<k;i++)
		{
			scanf("%d%d%lld",&u,&v,&w);
			edge_list.push_back(make_pair(u,make_pair(v,w)));
		}
		
		for(i=0;i<=n;i++)
		d[i]=INF;
		
		dijkstra1(n,start);
		shortest_dist=d[dest];  //printf("%d\n",shortest_dist);
		
		for(i=0;i<=n;i++)
		d_rev[i]=INF;
		
		dijkstra2(n,dest);
		
		for(i=0;i<k;i++)
		{
			int u=edge_list[i].first;   int v=edge_list[i].second.first;    int w=edge_list[i].second.second;
			//cout<<"u="<<u<<"v="<<v<<"w="<<w;
			if(d[u]+w+d_rev[v]<shortest_dist)
			shortest_dist=d[u]+w+d_rev[v];
			if(d[v]+w+d_rev[u]<shortest_dist)
			shortest_dist=d[v]+w+d_rev[u];
		}
		if(shortest_dist!=INF)
		printf("%lld\n",shortest_dist);
		else
		printf("-1\n");
	}
	return 0;
}
