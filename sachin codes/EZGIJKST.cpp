#include<bits/stdc++.h>
using namespace std;
#define maxn 100003
#define inf 1000000000

vector<vector<pair<int,int> > > g; 
vector<int> d; 
vector<int> p;
priority_queue<pair<int,int> > pq;//    first element of pair is label on the vertex
                                         //     ie  the minimum distace explored upto that instant;
void Dijkstra(int n,int start)            //    and the second is the vertex itself;
{
	d[start]=0;
	pq.push(make_pair(0,start));
	while(!pq.empty())
	{
		int v=pq.top().second;     int curr_dis=-pq.top().first;// by default it stores max element on top
		                                                            //so we are storing their negative values;
		pq.pop();          //   deleting top of heap having minimum label
		if(curr_dis>d[v])          // becouse as we could not delete elements from priority queue so inorder to avoid
		continue;                  // same vertex to appear again we are doing this;
		
		for(int j=0;j<g[v].size();j++)
		{
			int neigh=g[v][j].first;
			int length=g[v][j].second;
			if(d[v]+length<d[neigh])
			{
				d[neigh]=d[v]+length;
				pq.push(make_pair(-d[neigh],neigh));
				p[neigh]=v;
			}
		}
	}
}

int main()
{
	int u,v,w,i,n,m,source,sink,t;
	scanf("%d",&t);
	while(t--)
	{
		g.clear();
		d.clear();
		p.clear();
		
		scanf("%d%d",&n,&m);
		g.resize(n+1);
		p.resize(n+1);
		d.resize(n+1);
		for(i=0;i<=n;i++)
		d[i]=inf;
		
   		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			g[u].push_back(make_pair(v,w));
		//	g[v].push_back(make_pair(u,w));
		}	
		scanf("%d%d",&source,&sink);
		
		Dijkstra(n,source);
	
	    if(d[sink]!=inf)
	    printf("%d\n",d[sink]);
	    else
	    printf("NO\n");
	}
    
	return 0;
}
