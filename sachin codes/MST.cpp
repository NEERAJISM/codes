#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define inf 1000000000

vector<int> res_edge;

//    first element of pair is wieght and and second is label on the vertex
                                         //     ie  the minimum edge length going from s to :s: across the cut;
long long int Prim(int n,int start,vector<vector<pair<int,int> > > &g,vector<int> &d,vector<bool> &mark_set)
{	long long int sum=0,i,j;
	priority_queue<pair<int,int> > pq;
	for(i=1;i<=n;i++)
	mark_set[i]=false;
	
	d[start]=0;
	pq.push(make_pair(0,start));
	while(!pq.empty())
	{
		long long int v=pq.top().second;     long long int curr_dis=-pq.top().first;// by default it stores max element on top
																//so we are storing their negative values;
		mark_set[v]=true;       
		                   
		pq.pop();                    //   deleting top of heap having minimum label
		
		if(curr_dis>d[v])          // becouse as we could not delete elements from priority queue so inorder to avoid
		continue;                  // same vertex to appear again we are doing this;
		
		res_edge.push_back(curr_dis);  
		sum+=curr_dis;
		
		for(j=0;j<g[v].size();j++)
		{
			long long int neigh=g[v][j].first;
			long long int length=g[v][j].second;
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
	return sum;
}

int main()
{
	long long int u,v,w,i,n,m,source,sink,t,p,sum;
	scanf("%lld",&t);
	while(t--)
	{	scanf("%lld",&p);
	scanf("%lld%lld",&n,&m);

vector<vector<pair<int,int> > > g(n+1); 
vector<int> d(n+1,inf); 
vector<bool> mark_set(n+1);
    
    //g.resize(n+1);
	while(m--)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}	
//	cout<<"your minimum spanning tree will have following edges\n";
	sum=Prim(n,1,g,d,mark_set);
	//for(i=1;i<res_edge.size();i++)
//	cout<<res_edge[i]<<"  ";
printf("%lld\n",sum*p);}
	return 0;
}
