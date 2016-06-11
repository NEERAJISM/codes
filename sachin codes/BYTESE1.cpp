#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define pp pair<int,int>
#define pp1 pair<int,pair<int,int> >

int g[102][102];
int d[102][102];
priority_queue<pair<int,pair<int,int> > > pq;

void make_infinite(int r,int c)
{
	int i,j;
	for(i=1;i<=r;i++)
	for(j=1;j<=c;j++)
	{
		d[i][j]=inf;
	}
}

void Dijkstra(int r,int c,int sx,int sy)    
{
	int nx,ny,len;
	d[sx][sy]=g[sx][sy];
	pq.push(pp1(-d[sx][sy],pp(sx,sy)));
	while(!pq.empty())
	{
		int vx=pq.top().second.first;    int vy=pq.top().second.second;     int curr_dis=-pq.top().first;
		                                  //cout<<"vx="<<vx<<"vy="<<vy<<"curr dis="<<curr_dis<<endl;                        
		pq.pop();          
		if(curr_dis>d[vx][vy])         
		continue;               
		
			nx=vx+1;    ny=vy;       len=g[nx][ny];
			if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&d[vx][vy]+len<d[nx][ny])
			{
				d[nx][ny]=d[vx][vy]+len;
				pq.push(pp1(-d[nx][ny],pp(nx,ny)));
			}
			
			nx=vx-1;    ny=vy;       len=g[nx][ny];
			if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&d[vx][vy]+len<d[nx][ny])
			{
				d[nx][ny]=d[vx][vy]+len;
				pq.push(pp1(-d[nx][ny],pp(nx,ny)));
			}
			
			nx=vx;    ny=vy+1;       len=g[nx][ny];
			if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&d[vx][vy]+len<d[nx][ny])
			{
				d[nx][ny]=d[vx][vy]+len;
				pq.push(pp1(-d[nx][ny],pp(nx,ny)));
			}
			
			nx=vx;    ny=vy-1;       len=g[nx][ny];
			if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&d[vx][vy]+len<d[nx][ny])
			{
				d[nx][ny]=d[vx][vy]+len;
				pq.push(pp1(-d[nx][ny],pp(nx,ny)));
			}
	}
}

int main()
{
	int i,j,r,c,t,x,y,time,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
		{
			cin>>g[i][j];
		}
		
		make_infinite(r,c);
		
		scanf("%d%d%d",&x,&y,&time);
		
		Dijkstra(r,c,1,1);
		ans=d[x][y];

		
		if(ans<=time)
		{
			printf("YES\n");
			printf("%d\n",time-ans);
		}
		else
		printf("NO\n");
	}
	return 0;
}
