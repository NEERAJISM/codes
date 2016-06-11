#include<bits/stdc++.h>
using namespace std;
#define INF 10611095

vector<vector<pair<int,int> > > g;
vector<int> d;

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

int main()
{
	int n,m,start,dest,time,k,i,j,u,v,E;
	int w,ans;

	
		scanf("%d%d%d%d",&n,&E,&time,&m);
		
		g.clear();
	    g.resize(n+1);
	    d.resize(n+1);
	    
	  	while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			g[v].push_back(make_pair(u,w));
		}

		for(i=0;i<=n;i++)
		d[i]=INF;
		
		dijkstra1(n,E);
	
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(d[i]<=time)
			ans++;
		}
		printf("%d\n",ans);
		
	return 0;
}
