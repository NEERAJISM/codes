#include<bits/stdc++.h>
using namespace std;

char g[102][102];
int visited[102][102];
int count_visited[102][102];
int flag;
char xx[]="ALLIZZWELL";

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
		int nx,ny;   // cout<<"count="<<count<<g[sx][sy]<<"  ";
	if(count==10)
	{
		flag=1;
		return ;
	}
	   	nx=sx+1;   ny=sy;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==xx[count])
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
		        nx=sx-1;   ny=sy;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==xx[count])
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
		        nx=sx;   ny=sy+1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==xx[count])
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx;   ny=sy-1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==xx[count])
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx+1;   ny=sy+1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==xx[count])
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx+1;   ny=sy-1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==xx[count])
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx-1;   ny=sy+1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==xx[count])
		{
			visited[nx][ny]=1;
			count_visited[nx][ny]++;
			dfs(nx,ny,r,c,count+1);
			if(count_visited[nx][ny]<8)
			visited[nx][ny]=0;
		}
		
				nx=sx-1;   ny=sy-1;
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&visited[nx][ny]==0&&g[nx][ny]==xx[count])
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
	int i,j,r,c,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
		{
			cin>>g[i][j];
		}
		make_unvisited(r,c);
		flag=0;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(g[i][j]=='A')
				{
					//flag=0;
					dfs(i,j,r,c,1);
					make_unvisited(r,c);
					if(flag==1)
					break;
				}
			}
			if(flag==1)
			break;
		}//cout<<endl;
		if(flag==1)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
