#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int> > > g;
vector<int> parent(100);
vector<int> rank(100);
vector<pair<int,int> > res;
int sum=0;

void make_set(int v) 	
{
	 parent[v]=v;
	 rank[v]=0;
}
 
int find_set(int v)
{
	 if(v==parent[v])
	  return v;
	 return find_set(parent[v]);
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
void kruskal(int m)
{
	 for(int i=0;i<m;i++)
	 {
		  int a=g[i].second.first;
		  int b=g[i].second.second;
		  int len=g[i].first;
		  int y=find_set(a);
		  int z=find_set(b);
		  if(y!=z)
		  {
			   sum+=len;
			   union_set(a,b);
			   res.push_back(make_pair(a,b));
		  }
	 }
 
}

int main()
{
	 int u,v,w,i,n,m,x;
	 cout<<" enter no of vertices and no of edges\n" ;
	 cin>>n>>m;
	 x=m;
	 //g.resize(m+2);
	 cout<<" enter the edges with wieghts\n" ;
	 while(m--)
	 {
		  cin>>u>>v>>w;
		  g.push_back(make_pair(w,make_pair(u,v)));
	 }
	 sort(g.begin(),g.end());
	 
	 for(i=1;i<=n;i++)
	 parent[i]=i;
	 //for(i=1;i<=n;i++)
	 //cout<<parent[i]<<"  " ;
	 
	 kruskal(x);
	 cout<<"weight of minimum spanning tree is = "<<sum<<endl;
	 cout<<" and the edges are\n"; 
	 for(i=0;i<res.size();i++)
	 cout<<res[i].first<<" - "<<res[i].second<<endl;
	 
	 return 0;
}
