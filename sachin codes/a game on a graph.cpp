#include<bits/stdc++.h>
using namespace std;
#define inf 10000

vector<vector<int> > g;
vector<int> visited;
vector<int> ans;
vector<int> res;
vector<int> distances;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start]=1;
	distances[start]=0;
	
	while(!(q.empty()))
	{                                
		int curr_ver=q.front();  //cout<<"ver="<<curr_ver<<endl;
		visited[curr_ver]=2;
		int dist=distances[curr_ver];
		q.pop();
		int flag=0;
		for(int k=0;k<g[curr_ver].size();k++)
		{
			int neigh=g[curr_ver][k];
			if(visited[neigh]==0||visited[neigh]==1)
			flag=1;	
		}
			if(flag==0)
			{
				if(dist%2==0)
				{
					if(ans[curr_ver]==0)
					ans[curr_ver]=dist;
					else if(-ans[curr_ver]>dist)
					ans[curr_ver]=dist;
				}
				else
				{
					if(ans[curr_ver]==0)
					ans[curr_ver]=-dist;
					else if(ans[curr_ver]>dist)
					ans[curr_ver]=-dist;
				}
			}
			else
			{
				for(int i=0;i<g[curr_ver].size();i++)
				{
					int curr_neigh=g[curr_ver][i];
					if(!visited[curr_neigh])
					{
						visited[curr_neigh]=1;
						distances[curr_neigh]=distances[curr_ver]+1;
						q.push(curr_neigh);
						
					}
				}
			}
	
	}
}

void make_unvisited(int n)
{
	for(int i=1;i<=n;i++)
	visited[i]=0;
}

void make_ans_zero(int n)
{
	for(int i=1;i<=n;i++)
	{
		ans[i]=0;
		distances[i]=0;
	}
}

void check_node(int v,int n)
{
	cout<<"v="<<v<<endl;
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<"  ";
	cout<<endl;
	
	int min_negative=inf;  int min_positive=inf;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]>0)
		{
			if(ans[i]<min_positive)
			min_positive=ans[i];
		}
		else if(ans[i]<0)
		{
			if(-ans[i]<min_negative)
			min_negative=-ans[i];
		}
	}
	
	if(min_positive<min_negative)
	res[v]=1;
	else 
	res[v]=0;
}

int main()
{
	int i,u,v,n,m,t,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		g.clear();
		visited.clear();
		ans.clear();
		res.clear();
		distances.clear();
		
		g.resize(n+2);
		visited.resize(n+2);
		ans.resize(n+2);
		res.resize(n+2);
		distances.resize(n+2);
		
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}	
		
		for(i=1;i<=n;i++)
		{
			make_unvisited(n);
			make_ans_zero(n);
			//visited[i]=1;
			bfs(i);
			check_node(i,n);
		}
		
		count=0;
		for(i=1;i<=n;i++)
		if(res[i]==1)
		count++;
		
		printf("%d\n",count);
	}
	return 0;
}
