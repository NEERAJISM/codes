#include<bits/stdc++.h>
using namespace std;
#define INF 10611095

vector<vector<pair<int,int> > > g;
vector<double> d;

void dijkstra1(int n,int start)
{
	priority_queue<pair<double,int> > pq;
	d[start]=1;
	pq.push(make_pair(1,start));
	
	while(!pq.empty())
	{
		int v=pq.top().second;  double curr_dis=pq.top().first;
		pq.pop();
		
		if(curr_dis<d[v])
		continue;
		
		for(int j=0;j<g[v].size();j++)
		{
			int neigh=g[v][j].first;
			double len=g[v][j].second;     len=len/100;
			
			if(d[v]*len>d[neigh])
			{
				d[neigh]=d[v]*len;
				pq.push(make_pair(d[neigh],neigh));
			}
		}
	}
}

int main()
{
	int n,m,start,dest,time,k,i,j,u,v,E;
	int w;
	double ans;
	
	while(1)
	{
	
		scanf("%d",&n);
		if(n==0)
		break;
		
		scanf("%d",&m);
		
		g.clear();
	    g.resize(n+1);
	    d.resize(n+1);
	    
	  	while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			g[u].push_back(make_pair(v,w));
			g[v].push_back(make_pair(u,w));
		}

		for(i=0;i<=n;i++)
		d[i]=0;
		
		dijkstra1(n,1);
		ans=d[n];
		ans=ans*100;
		
		printf("%.6lf percent\n",ans);
	}
	return 0;
}
