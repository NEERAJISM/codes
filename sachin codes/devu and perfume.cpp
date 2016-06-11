#include<bits/stdc++.h>
using namespace std;

char a[1002][1002];
int visited[1002][1002],level[1002][1002];

void make_unvisited(int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			visited[i][j]=0;  level[i][j]=0;
		}
	}
}

int bfs(int n,int m,int stx,int sty)
{
	int maxl=0;
	visited[stx][sty]=1;
	level[stx][sty]=0;
	queue<pair<int,int> > q;
	q.push(make_pair(stx,sty));
	int nx,ny,vx,vy;
	
	while(!(q.empty()))
	{
		vx=q.front().first;    vy=q.front().second;      q.pop();
		nx=vx+1;  ny=vy+1;
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 )
		{
			q.push(make_pair(nx,ny));
			visited[nx][ny]=1;         level[nx][ny]=level[vx][vy]+1;
			if(a[nx][ny]=='*'&&level[nx][ny]>maxl)
			maxl=level[nx][ny];
		}
		
		nx=vx+1;  ny=vy-1;
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 )
		{
			q.push(make_pair(nx,ny));
			visited[nx][ny]=1;         level[nx][ny]=level[vx][vy]+1;
			if(a[nx][ny]=='*'&&level[nx][ny]>maxl)
			maxl=level[nx][ny];
		}
		
		nx=vx-1;  ny=vy+1;
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 )
		{
			q.push(make_pair(nx,ny));
			visited[nx][ny]=1;         level[nx][ny]=level[vx][vy]+1;
			if(a[nx][ny]=='*'&&level[nx][ny]>maxl)
			maxl=level[nx][ny];
		}
		
		nx=vx-1;  ny=vy-1;
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 )
		{
			q.push(make_pair(nx,ny));
			visited[nx][ny]=1;         level[nx][ny]=level[vx][vy]+1;
			if(a[nx][ny]=='*'&&level[nx][ny]>maxl)
			maxl=level[nx][ny];
		}
		
		nx=vx;  ny=vy+1;
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 )
		{
			q.push(make_pair(nx,ny));
			visited[nx][ny]=1;         level[nx][ny]=level[vx][vy]+1;
			if(a[nx][ny]=='*'&&level[nx][ny]>maxl)
			maxl=level[nx][ny];
		}
		
		nx=vx;  ny=vy-1;
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 )
		{
			q.push(make_pair(nx,ny));
			visited[nx][ny]=1;         level[nx][ny]=level[vx][vy]+1;
			if(a[nx][ny]=='*'&&level[nx][ny]>maxl)
			maxl=level[nx][ny];
		}
		
		nx=vx+1;  ny=vy;
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 )
		{
			q.push(make_pair(nx,ny));
			visited[nx][ny]=1;         level[nx][ny]=level[vx][vy]+1;
			if(a[nx][ny]=='*'&&level[nx][ny]>maxl)
			maxl=level[nx][ny];
		}
		
		nx=vx-1;  ny=vy;
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 )
		{
			q.push(make_pair(nx,ny));
			visited[nx][ny]=1;         level[nx][ny]=level[vx][vy]+1;
			if(a[nx][ny]=='*'&&level[nx][ny]>maxl)
			maxl=level[nx][ny];
		}
		 
	}
	return maxl;
}

int main()
{
	int t,n,m,i,j,l;
	string s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int sum_x,sum_y,maxl,minl,ans;
		for(i=0;i<n;i++)
		{
			cin>>s;
			for(j=0;j<m;j++)
			a[i][j]=s[j];
		}
		make_unvisited(n,m);
		
		int left_x=n,right_x=-1,top_y=m,bottom_y=-1;  bool flag=false;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='*')
				{
					flag=true;
					
					if(i<left_x)
					left_x=i;
					if(i>right_x)
					right_x=i;
					if(j<top_y)
					top_y=j;
					if(j>bottom_y)
					bottom_y=j;
				}
			}
		}
		
		
		if(!flag)
		{
			printf("0\n");
		}
		else
		{
			sum_x=(right_x+left_x);   
			sum_y=(bottom_y+top_y);
			
			ans=bfs(n,m,sum_x/2,sum_y/2);
			
			printf("%d\n",ans+1);
		}
	}
	return 0;
}
