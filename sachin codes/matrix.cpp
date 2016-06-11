#include<bits/stdc++.h>
using namespace std;

int g[1002][1002],visited[1002][1002];

void make_graph_clear(int n,int m)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			g[i][j]=0;
		}
	}
}
void make_unvisited(int n,int m)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			visited[i][j]=0;
		}
	}
}

int bfs(int n,int m,int startx,int starty)
{
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
	visited[startx][starty]=1;
	int coun=0;

	int curr_neigh_x,curr_neigh_y;
	
	while(!(q.empty()))
	{                             
		int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();
		coun++;
		////cout<<curr_ver_x<<"   "<<curr_ver_y<<"  "<<coun<<endl;
		         //cout<<"coun="<<coun;
			curr_neigh_x=(curr_ver_x)+1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]!=-2&&g[curr_neigh_x][curr_neigh_y]!=-3)
			{
				visited[curr_neigh_x][curr_neigh_y]=1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
				//count++;
		}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)+1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]!=-1&&g[curr_neigh_x][curr_neigh_y]!=-3)
			{
				visited[curr_neigh_x][curr_neigh_y]=1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
				//count++;
			}
			
			curr_neigh_x=(curr_ver_x)-1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_ver_x][curr_ver_y]!=-2&&g[curr_ver_x][curr_ver_y]!=-3)
			{
				visited[curr_neigh_x][curr_neigh_y]=1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
				//count++;
			}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)-1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_ver_x][curr_ver_y]!=-1&&g[curr_ver_x][curr_ver_y]!=-3)
			{
				visited[curr_neigh_x][curr_neigh_y]=1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
				//count++;
			}
	}
	return coun;
}
int bfs1(int n,int m,int startx,int starty,int sinkx,int sinky)
{
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
	visited[startx][starty]=1;
	int flag=0;

	int curr_neigh_x,curr_neigh_y;
	
	while(!(q.empty()))
	{                             
		int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();
		if(curr_ver_x==sinkx&&curr_ver_y==sinky)
		{
			flag=1;
			break;
		}
		////cout<<curr_ver_x<<"   "<<curr_ver_y<<"  "<<coun<<endl;
		         //cout<<"coun="<<coun;
			curr_neigh_x=(curr_ver_x)+1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]!=-2&&g[curr_neigh_x][curr_neigh_y]!=-3)
			{
				visited[curr_neigh_x][curr_neigh_y]=1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
				//count++;
		}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)+1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]!=-1&&g[curr_neigh_x][curr_neigh_y]!=-3)
			{
				visited[curr_neigh_x][curr_neigh_y]=1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
				//count++;
			}
			
			curr_neigh_x=(curr_ver_x)-1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_ver_x][curr_ver_y]!=-2&&g[curr_ver_x][curr_ver_y]!=-3)
			{
				visited[curr_neigh_x][curr_neigh_y]=1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
				//count++;
			}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)-1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_ver_x][curr_ver_y]!=-1&&g[curr_ver_x][curr_ver_y]!=-3)
			{
				visited[curr_neigh_x][curr_neigh_y]=1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
				//count++;
			}
	}
	if(flag==1)
	return true;
	else
	return false;
}
int main()
{
	int t,n,m,q,i,j,u,v,ans,id,x,y,x1,x2,y1,y2;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d%d",&n,&m,&q);
		make_graph_clear(n,m);
		while(q--)
		{
			scanf("%d",&id);
			if(id==1)
			{
				scanf("%d%d",&x,&y);
				if(g[x][y+1]==-2)
				g[x][y+1]=-3;
				else if(g[x][y+1]==0)
				g[x][y+1]=-1;
			}
			if(id==2)
			{
				scanf("%d%d",&x,&y);
				if(g[x+1][y]==-1)
				g[x+1][y]=-3;
				else if(g[x+1][y]==0)
				g[x+1][y]=-2;
			}
			if(id==3)
			{
				make_unvisited(n,m);
				int l;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				if(bfs1(n,m,x1,y1,x2,y2))
				ans+=1;
				
			}
			if(id==4)
			{
				make_unvisited(n,m);
				int co=0,count=0;
	/*			for(i=1;i<=n;i++)
				{
					for(j=1;j<=m;j++)
					{
						cout<<g[i][j]<<" ";
					}
					cout<<endl;
				}
	*/			for(i=1;i<=n;i++)
				{
					for(j=1;j<=m;j++)
					{
						if(visited[i][j]!=1)
						{
							count=bfs(n,m,i,j);
							if(count>co)
							co=count;
						}
					}
				}
				ans+=co;
			}
			//cout<<ans<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
