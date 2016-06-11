#include<bits/stdc++.h>
using namespace std;

#define maxn 1000000
#define inf 1000000000

vector <pair <int, pair <int, int> > > g(maxn);  
vector<int> parent(maxn);
vector<int> rank(maxn);
vector<int> res_edge;
vector<pair<int,int> > res_ver_pair;

void make_set(int v)
{
	parent[v]=v;
	rank[v]=0;
}

int find_set(int v)
{
	if(v==parent[v])
	return v;
	else
	return find_set (parent[v]);
}

void union_set(int a,int b)
{
	int root_a=find_set(a);
	int root_b=find_set(b);
	
	if(root_a!=root_b)
	{
		if(rank[root_a]<rank[root_b])
		swap(root_a,root_b);
		
		parent[root_b]=root_a;
		if(rank[root_a]==rank[root_b])
		++rank[root_a];
    }
}

bool compares(const vector<pair<int,pair<int,int> > > &ii, const vector<pair<int,pair<int,int> > > &jj)
{
    return ii.first < jj.first;
}

void Kruskal(int m)
{
	for(int i=0;i<m;i++)
	{
		int a=g[i].second.first;
		int b=g[i].second.second; 
		int length=g[i].first;
		
		if(find_set(a)!=find_set(b))
		{
			res_ver_pair.push_back(make_pair(a,b));
			res_edge.push_back(length);
			union_set(a,b);
		}
	}
}

int main()
{
	int u,v,w,i,n,m;
    cin>>n>>m;
    g.resize(n+1);
    
	for(i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		g[i].push_back(pair<int,pair<int,int> >(w,pair<int,int>(u,v)));
	}
	
	sort(g.begin(),g.end(),compares);	
	cout<<"your minimum spanning tree will have following edges\n";
	
	Kruskal(m);  // no of edges
	
	for(i=1;i<res_edge.size();i++)
	cout<<res_ver_pair[i].first<<"-"<<res_ver_pair[i].second<<"="<<res_edge[i]<<endl;
	
	return 0;
}
