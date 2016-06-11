#include<bits/stdc++.h>
using namespace std;
#define inf 500;

int g[200][200];
int visited[200][200];
int dist[200][200];

void make_unvisited(int n,int m)
{
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			visited[i][j]=0;
		}
	}
}

void bfs(int st_x,int st_y,int n,int m)
{
	visited[st_x][st_y]=1;
	queue<pair<int,int> > q;
	q.push(make_pair(st_x,st_y));
	dist[st_x][st_y]=0;
	
	while(!(q.empty()))
	{
		int ver_x=q.front().first;   int ver_y=q.front().second;   int neigh_x; int neigh_y;
		q.pop();
		
		neigh_x=ver_x+1;  neigh_y=ver_y;
		if(neigh_x<=n&&neigh_x>=1&&neigh_y<=m&&neigh_y>=1&&visited[neigh_x][neigh_y]==0)
		{
			visited[neigh_x][neigh_y]=1;
			if(g[neigh_x][neigh_y]!=1)
			dist[neigh_x][neigh_y]=min(dist[neigh_x][neigh_y],dist[ver_x][ver_y]+1);
			else
			dist[neigh_x][neigh_y]=0;
			q.push(make_pair(neigh_x,neigh_y));
		}
		
		neigh_x=ver_x-1;  neigh_y=ver_y;
		if(neigh_x<=n&&neigh_x>=1&&neigh_y<=m&&neigh_y>=1&&visited[neigh_x][neigh_y]==0)
		{
			visited[neigh_x][neigh_y]=1;
			if(g[neigh_x][neigh_y]!=1)
			dist[neigh_x][neigh_y]=min(dist[neigh_x][neigh_y],dist[ver_x][ver_y]+1);
			else
			dist[neigh_x][neigh_y]=0;
			q.push(make_pair(neigh_x,neigh_y));
		}
		
		neigh_x=ver_x;  neigh_y=ver_y+1;
		if(neigh_x<=n&&neigh_x>=1&&neigh_y<=m&&neigh_y>=1&&visited[neigh_x][neigh_y]==0)
		{
			visited[neigh_x][neigh_y]=1;
			if(g[neigh_x][neigh_y]!=1)
			dist[neigh_x][neigh_y]=min(dist[neigh_x][neigh_y],dist[ver_x][ver_y]+1);
			else
			dist[neigh_x][neigh_y]=0;
			q.push(make_pair(neigh_x,neigh_y));
		}
		
		neigh_x=ver_x;  neigh_y=ver_y-1;
		if(neigh_x<=n&&neigh_x>=1&&neigh_y<=m&&neigh_y>=1&&visited[neigh_x][neigh_y]==0)
		{
			visited[neigh_x][neigh_y]=1;
			if(g[neigh_x][neigh_y]!=1)
			dist[neigh_x][neigh_y]=min(dist[neigh_x][neigh_y],dist[ver_x][ver_y]+1);
			else
			dist[neigh_x][neigh_y]=0;
			q.push(make_pair(neigh_x,neigh_y));
		}
	}
}

int main()
{
	int n,m,i,j,x,t;
	char s[200];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				dist[i][j]=inf;
			}
		}
		
		for(i=1;i<=n;i++)
		{
			cin>>s;
			int l=strlen(s);
			for(j=0;j<l;j++)
			{
				g[i][j+1]=(int)(s[j]-'0');
			}
		}
		
		int flag=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(g[i][j])
				{
					make_unvisited(n,m);
					bfs(i,j,n,m);
					flag=1;
					break;
				}
			}
			if(flag)
			break;
		}
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cout<<dist[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
