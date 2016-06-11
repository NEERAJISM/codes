#include<bits/stdc++.h>
using namespace std;

int g[9][9],level[9][9];

void bfs(int startx,int starty)
{
	int n=8,m=8;
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
	g[startx][starty]=1;
	level[startx][starty]=0;

	int curr_neigh_x,curr_neigh_y;
	
	while(!(q.empty()))
	{                             
		int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();

			curr_neigh_x=(curr_ver_x)+1;           //1
			curr_neigh_y=(curr_ver_y)+2;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				level[curr_neigh_x][curr_neigh_y]=level[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x)-1;          //2
			curr_neigh_y=(curr_ver_y)+2;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				level[curr_neigh_x][curr_neigh_y]=level[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x)+1;          //3
			curr_neigh_y=(curr_ver_y)-2;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				level[curr_neigh_x][curr_neigh_y]=level[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
						
			curr_neigh_x=(curr_ver_x)-1;          //4
			curr_neigh_y=(curr_ver_y)-2;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				level[curr_neigh_x][curr_neigh_y]=level[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x)+2;          //5
			curr_neigh_y=(curr_ver_y)+1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				level[curr_neigh_x][curr_neigh_y]=level[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x)+2;           //6
			curr_neigh_y=(curr_ver_y)-1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				level[curr_neigh_x][curr_neigh_y]=level[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x)-2;            //7
			curr_neigh_y=(curr_ver_y)+1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				level[curr_neigh_x][curr_neigh_y]=level[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x)-2;           //8
			curr_neigh_y=(curr_ver_y)-1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				level[curr_neigh_x][curr_neigh_y]=level[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
	}
}



int main()
{
	int t,i,j,x1,x2,y1,y2;
	char c1[3],c2[3];
	scanf("%d",&t);
	while(t--)
	{
		cin>>c1;
		cin>>c2;
		x1=c1[0]-'a'+1;    x2=c2[0]-'a'+1;
		y1=c1[1]-'0';      y2=c2[1]-'0';           //cout<<"x1="<<x1;cout<<"x2="<<x2;cout<<"y1="<<y1;cout<<"y2="<<y2;
		
		for(i=1;i<=8;i++)
		for(j=1;j<=8;j++)
		{
			g[i][j]=0;
			level[i][j]=-1;
		}
		
		bfs(x1,y1);
		
		int ans=level[x2][y2];
		printf("%d\n",ans);
		
	}
	return 0;
}
