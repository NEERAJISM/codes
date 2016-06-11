#include<bits/stdc++.h>
using namespace std;

char g[52][52];
int visited[52][52];
int count_visited[52][52];
int ans=0;
//char xx[]="";

void make_unvisited(int r,int c)
{
	int i,j;
	for(i=1;i<=r;i++)
	for(j=1;j<=c;j++)
	{
		visited[i][j]=0;
		count_visited[i][j]=0;
	}
}
void dfs(int sx,int sy,int r,int c,int count)
{
		int nx,ny;              // cout<<"count="<<count<<g[sx][sy]<<"  ";
	if(count>ans)
	{
		ans=count;
	}
	   	nx=sx+1;   ny=sy;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==(char)('A'+count))
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
		        nx=sx-1;   ny=sy;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==(char)('A'+count))
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
		        nx=sx;   ny=sy+1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==(char)('A'+count))
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx;   ny=sy-1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==(char)('A'+count))
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx+1;   ny=sy+1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==(char)('A'+count))
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx+1;   ny=sy-1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==(char)('A'+count))
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx-1;   ny=sy+1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==(char)('A'+count))
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx-1;   ny=sy-1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==(char)('A'+count))
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
}

int main()
{
	int i,j,r,c,t=0;
	//scanf("%d",&t);
	while(1)
	{
		t++;
		scanf("%d%d",&r,&c);
		
		if(r==0&&c==0)
		break;
		
		ans=0;
		for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
		{
			cin>>g[i][j];
		}
		make_unvisited(r,c);
		
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(g[i][j]=='A')
				{
					dfs(i,j,r,c,1);
					make_unvisited(r,c);
				}
			}
		}
		cout<<"Case "<<t<<": "<<ans<<endl;
	}
	return 0;
}
