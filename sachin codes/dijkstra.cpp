#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define inf 1000000000

vector<vector<pair<int,int> > > g(maxn);
vector<int> d(maxn,inf);
vector<int>p(maxn);
priority_queue<pair<int,int> > pq;//    first element of pair is wieght and and second is label on the vertex
                                         //     ie  the minimum distace explored upto that instant;
void Dijkstra(int n,int start)
{
	d[start]=0;
	pq.push(make_pair(0,start));
	while(!pq.empty())
	{
		int v=pq.top().second;              // by default it stores max element on top
	    int curr_dis=-pq.top().first;	    //so we are storing their negative values;
		pq.pop();                           //deleting top of heap having minimum label
		if(curr_dis>d[v])                   // because as we could not delete elements from priority queue so inorder to avoid
		continue;                           // same vertex to appear again we are doing this;

		for(int j=0;j<g[v].size();j++)
		{
			int neigh=g[v][j].first;
			int length=g[v][j].second;
			if(d[v]+length<d[neigh])
			{
				d[neigh]=d[v]+length;
				pq.push(make_pair(-d[neigh],neigh));
				p[neigh]=v;                 //to store the neighbor
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
		g[u].push_back(make_pair(v,w));
	}
	cout<<"enter the source and sink vertex\n";
	cin>>source>>sink;
	Dijkstra(n,source);
	cout<<"least distance = "<<d[sink];
	return 0;
}
