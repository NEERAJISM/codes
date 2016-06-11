#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000

vector<vector<int> > g(maxn+1);
vector<int> visited(maxn+1);

bool bfs(int n,int start)
{
	//int flag=0;
	queue<int> q;
	q.push(start);
	visited[start]=1;
	
	while(!(q.empty()))
	{                                
		int curr_ver=q.front();
		q.pop();
		for(int i=0;i<g[curr_ver].size();i++)
		{
			int curr_neigh=g[curr_ver][i];
			if(visited[curr_neigh]==0)
			{
			
				q.push(curr_neigh);
				if(visited[curr_ver]==1)
				visited[curr_neigh]=2;
				else
				visited[curr_neigh]=1;
			}
			else
			{
				if(visited[curr_neigh]==visited[curr_ver])
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	int i,u,v,n,m,t,x,y;
    scanf("%d",&t);
    int cc=1;
    while(t--)
    {
    	g.clear(); visited.clear(); //distances.clear();
    	
    	scanf("%d%d",&n,&m);
    	visited.resize(n+2);
		
		for(i=0;i<n+2;i++)
		visited[i]=0;
    	
		g.resize(n+2);
		while(m--)
		{
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bool y;x=0;
    	for(i=1;i<=n;i++)
    	{
    		if(visited[i]==0)
    		{
    			y=bfs(n,i);
    			if(y==0)
    			{
    				x++;
    			}
    		}
    		
    	}
		
		if(x!=0)
		printf("Scenario #%d:\nSuspicious bugs found!\n",cc);
		else
		printf("Scenario #%d:\nNo suspicious bugs found!\n",cc);
		cc++;
    }
	return 0;
}
