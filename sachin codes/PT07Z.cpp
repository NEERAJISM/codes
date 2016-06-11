#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> level;
vector<bool> visited;

void bfs(int start)
{
	int ver,neigh,i;
	queue<int> q;
	q.push(start);
	level[start]=0;
	visited[start]=true;
	
	while(!(q.empty()))
	{
		ver=q.front();
		q.pop();
		
		for(i=0;i<g[ver].size();i++)
		{
			neigh=g[ver][i];
			if(!visited[neigh])
			{
				visited[neigh]=true;
				level[neigh]=level[ver]+1;
				q.push(neigh);
			}
		}
	}
}

int main()
{
	int n,max,i,u,v,x,y;
	scanf("%d",&n);
	                     g.resize(n+1);
                     	level.resize(n+1);
                     	visited.resize(n+1);
    for(i=1;i<=n;i++)
	visited[i]=false;                 	
                     	
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(1);
	//for(i=1;i<=n;i++)
//	cout<<level[i]<<"   ";
	max=-1;
	for(i=1;i<=n;i++)
	{
		if(level[i]>max)
		{
			max=level[i];
			x=i;
		}
	}
//	cout<<"max1="<<max<<endl;
//	cout<<"x="<<x<<endl;
    for(i=1;i<=n;i++)
	visited[i]=false;
	level.clear();
	bfs(x);
	max=-1;
	for(i=1;i<=n;i++)
	{
		if(level[i]>max)
		{
			max=level[i];
			y=i;
		}
	}
	printf("%d\n",max);
	return 0;
}
