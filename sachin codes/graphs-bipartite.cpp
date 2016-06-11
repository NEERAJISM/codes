#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> visited(100);
vector<int> distances(100);
int flag=0;

void bfs(int n,int start)
{
	queue<int> q;
	q.push(start);
	visited[start]=true;
	distances[start]=0;
	
	while(!(q.empty()))
	{                                
		int curr_ver=q.front();
		q.pop();
		for(int i=0;i<g[curr_ver].size();i++)
		{
			int curr_neigh=g[curr_ver][i];
			if(!visited[curr_neigh])
			{
				visited[curr_neigh]=true;
				q.push(curr_neigh);
				distances[curr_neigh]=distances[curr_ver]+1;
			}
			else
			{
				if(distances[curr_neigh]==distances[curr_ver])
				{
					flag++;
					break;
				}
			}
		}
	}
}

int main()
{
	int i,u,v,n,m,t;
	scanf("%d%d",&n,&m);
	g.resize(n+1);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(n,1);
	if(flag!=0)
	cout<<"bipartite\n";
	else
	cout<<"no";
	
	return 0;
}
