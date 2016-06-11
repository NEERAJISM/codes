#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define inf 1000000000
long long int sum=0;
vector<vector<pair<int,int> > > g(maxn); 
vector<int> d(maxn,inf); 
vector<int> res_edge;
vector<bool> mark_set(maxn);
priority_queue<pair<int,int> > pq;//    first element of pair is wieght and and second is label on the vertex
                                         //     ie  the minimum edge length going from s to :s: across the cut;
void Prim(int n,int start)
{
	for(int i=1;i<=n;i++)
	mark_set[i]=false;
	
	d[start]=0;
	pq.push(make_pair(0,start));
	while(!pq.empty())
	{
		int v=pq.top().second;     int curr_dis=-pq.top().first;// by default it stores max element on top
																//so we are storing their negative values;
		mark_set[v]=true;       
		                   
		pq.pop();                    //   deleting top of heap having minimum label
		
		if(curr_dis>d[v])          // becouse as we could not delete elements from priority queue so inorder to avoid
		continue;                  // same vertex to appear again we are doing this;
		
		res_edge.push_back(curr_dis);  
		sum+=curr_dis;
		
		for(int j=0;j<g[v].size();j++)
		{
			int neigh=g[v][j].first;
			int length=g[v][j].second;
			if(mark_set[neigh]==false)
			{
				if(length<d[neigh])
				{
					d[neigh]=length;
					pq.push(make_pair(-d[neigh],neigh));
				}
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
		g[v].push_back(make_pair(u,w));
	}	
	cout<<"your minimum spanning tree will have following edges\n";
	Prim(n,1);
	//for(i=1;i<res_edge.size();i++)
//	cout<<res_edge[i]<<"  ";
printf("%lld\n",sum);
	return 0;
}
