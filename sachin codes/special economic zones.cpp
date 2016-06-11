#include<bits/stdc++.h>
using namespace std;
#define maxn 202

int n,total=0;
vector<vector<int> > g(maxn+1);
vector<int> visited(maxn+1);
vector<int> visited2(maxn+1);
vector<int> visited3(maxn+1);
vector<int> temp;

void bfs2(int start)
{
	queue<int> q2;
	q2.push(start);
	visited2[start]=1;
	
	while(!(q2.empty()))
	{                                
		int curr_ver=q2.front();
		q2.pop();
		for(int i=0;i<g[curr_ver].size();i++)
		{
			int curr_neigh=g[curr_ver][i];
			if(visited2[curr_neigh]==0)
			{
				q2.push(curr_neigh);
				if(visited2[curr_ver]==1)
				{
					visited2[curr_neigh]=2;
				//	cout<<"c2="<<curr_neigh<<endl;
				}
				else
				{
					visited2[curr_neigh]=1;
					//cout<<"c1="<<curr_neigh<<endl;
				}
			}
			else
			{
				if(visited2[curr_ver]==1)
				{
					if(visited2[curr_neigh]==1)
					{
						visited2[curr_neigh]=2;
						//cout<<"c2="<<curr_neigh<<endl;
					}
				}
			}
		}
    }
}

void dfs(int start,int tag)
{
	if(tag==1)
	visited2[start]=2;
	else if(tag==2)
	visited2[start]=1;
	for(int i=0;i<g[start].size();i++)
	{
		if(visited2[g[start][i]]==0)
		{
			dfs(g[start][i],visited2[start]);
		}
		else
		{
			if(visited2[g[start][i]]==1&&visited2[start]==1)
			visited2[g[start][i]]=2;
		}
	}
}

void func()
{
	int ans=0,v=0,c1,c2,x;
	for(int i=0;i<temp.size();i++)
	{
		c1=0;c2=0;
			for(int j=0;j<n+2;j++)
			visited2[j]=0;
			
		dfs(temp[i],2);
		for(int j=0;j<n+2;j++)
		{
			if(visited2[j]!=0)
			{
				if(visited2[j]==1)
				c1++;
				else if(visited2[j]==2)
				c2++;
			}
		}
		x=c1-c2;
		if(x>ans)
		{
			ans=x;
			v=temp[i];
		}
	}
//	cout<<"vertex="<<v<<"value="<<ans<<endl;
	total+=ans;
}

void bfs1(int start)
{
	queue<int> q;
	q.push(start);
	visited[start]=1;
	temp.push_back(start);
	
	while(!(q.empty()))
	{                                
		int curr_ver=q.front();
		q.pop();
		for(int i=0;i<g[curr_ver].size();i++)
		{
			int curr_neigh=g[curr_ver][i];
			if(visited[curr_neigh]==0)
			{
				temp.push_back(curr_neigh);
				q.push(curr_neigh);
				if(visited[curr_ver]==1)
				visited[curr_neigh]=2;
				else
				visited[curr_neigh]=1;
			}

		}
    }
    func();
}
int main()
{
	int i,u,v,m,x,y;
    g.clear(); visited.clear();
    	
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
		
   	for(i=1;i<=n;i++)
   	{
        if(visited[i]==0)
    	{
    		bfs1(i);
    		temp.clear();
        }
   	}
   	printf("%d\n",total);
	return 0;
}
