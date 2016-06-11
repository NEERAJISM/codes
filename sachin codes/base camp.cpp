#include<bits/stdc++.h>
using namespace std;

char g[1002][1002];
char e1[1002][1002];
int p1x[1002][1002];
int p1y[1002][1002];
char e2[1002][1002];
int p2x[1002][1002];
int p2y[1002][1002];
char e3[1002][1002];
int p3x[1002][1002];
int p3y[1002][1002];
int visited[1002][1002];

void bfs1(int h,int w,int startx,int starty)
{
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
    visited[startx][starty]=1;
    p1x[startx][starty]=0;    p1y[startx][starty]=0;
    //cout<<endl<<endl<<"hello"<<endl;
    int curr_neigh_x,curr_neigh_y;
    
    while(!(q.empty()))
    {
    	int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();
		  //cout<<curr_ver_x<<"  "<<curr_ver_y<<endl;
		if(g[curr_ver_x][curr_ver_y]=='d')
		break;
		
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=curr_ver_y;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p1x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p1y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x);
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p1x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p1y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=curr_ver_y;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p1x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p1y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x);
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p1x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p1y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p1x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p1y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p1x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p1y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p1x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p1y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p1x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p1y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
    }
}
void calc1(int startx,int starty,int endx,int endy)
{
	e1[startx][starty]='a';
	
	if(startx==endx&&starty==endy)
	return ;
	
	int x=p1x[startx][starty];
	int y=p1y[startx][starty];
	
	calc1(x,y,endx,endy);
}
void print1(int r,int c)
{
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(e1[i][j]=='s')
			e1[i][j]='-';
			cout<<e1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void bfs2(int h,int w,int startx,int starty)
{
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
    visited[startx][starty]=1;
    p2x[startx][starty]=0;    p2y[startx][starty]=0;
    //cout<<endl<<endl<<"hello"<<endl;
    int curr_neigh_x,curr_neigh_y;
    
    while(!(q.empty()))
    {
    	int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();
		  //cout<<curr_ver_x<<"  "<<curr_ver_y<<endl;
		if(g[curr_ver_x][curr_ver_y]=='d')
		break;
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=curr_ver_y;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p2x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p2y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x);
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
	     	p2x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p2y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=curr_ver_y;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p2x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p2y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x);
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p2x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p2y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p2x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p2y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p2x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p2y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p2x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p2y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p2x[curr_neigh_x][curr_neigh_y]=curr_ver_x;               p2y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
    }
}
void calc2(int startx,int starty,int endx,int endy)
{
	e2[startx][starty]='b';
	
	if(startx==endx&&starty==endy)
	return ;
	
	int x=p2x[startx][starty];
	int y=p2y[startx][starty];
	
	calc2(x,y,endx,endy);
}
void print2(int r,int c)
{
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(e2[i][j]=='s')
			e2[i][j]='-';
			cout<<e2[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void bfs3(int h,int w,int startx,int starty)
{
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
    visited[startx][starty]=1;
    p3x[startx][starty]=0;    p3y[startx][starty]=0;
    //cout<<endl<<endl<<"hello"<<endl;
    int curr_neigh_x,curr_neigh_y;
    
    while(!(q.empty()))
    {
    	int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();
		  //cout<<curr_ver_x<<"  "<<curr_ver_y<<endl;
		if(g[curr_ver_x][curr_ver_y]=='d')
		break;
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=curr_ver_y;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p3x[curr_neigh_x][curr_neigh_y]=curr_ver_x;   p3y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x);
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p3x[curr_neigh_x][curr_neigh_y]=curr_ver_x;  p3y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=curr_ver_y;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p3x[curr_neigh_x][curr_neigh_y]=curr_ver_x;  p3y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x);
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p3x[curr_neigh_x][curr_neigh_y]=curr_ver_x;  p3y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p3x[curr_neigh_x][curr_neigh_y]=curr_ver_x;p3y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p3x[curr_neigh_x][curr_neigh_y]=curr_ver_x;p3y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p3x[curr_neigh_x][curr_neigh_y]=curr_ver_x; p3y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&(g[curr_neigh_x][curr_neigh_y]=='d'||g[curr_neigh_x][curr_neigh_y]=='-'))
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			p3x[curr_neigh_x][curr_neigh_y]=curr_ver_x;p3y[curr_neigh_x][curr_neigh_y]=curr_ver_y;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
    }
}

void calc3(int startx,int starty,int endx,int endy)
{
	e3[startx][starty]='c';
	
	if(startx==endx&&starty==endy)
	return ;
	
	int x=p3x[startx][starty];
	int y=p3y[startx][starty];
	
	calc3(x,y,endx,endy);
}

void print3(int r,int c)
{
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(e3[i][j]=='s')
			e3[i][j]='-';
			cout<<e3[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int i,j,r,c,fx,fy;
	while(1)
	{
		scanf("%d",&r);
		if(r==-1)
		break;
		
		scanf("%d",&c);
	
	
		memset(visited,0,sizeof(visited));
			
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				cin>>g[i][j];
				e1[i][j]=g[i][j];  e2[i][j]=g[i][j];  e3[i][j]=g[i][j];
				if(g[i][j]=='d')
				{
					fx=i; fy=j;
				}
			}
		}
		
		int id=0;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(g[i][j]=='s')
				{
					id++;  //cout<<"id="<<id<<endl;
					memset(visited,0,sizeof(visited));
					if(id==1)
					{
						bfs1(r,c,i,j);    //cout<<"sach";
						calc1(fx,fy,i,j);//cout<<"sach";
						e1[fx][fy]='d';  
						print1(r,c);
					}
					else if(id==2)
					{
						bfs2(r,c,i,j);//cout<<"sach";
						calc2(fx,fy,i,j);//cout<<"sach";
						e2[fx][fy]='d';
						print2(r,c);
					}
					else if(id==3)
					{
						bfs3(r,c,i,j);
						calc3(fx,fy,i,j);
						e3[fx][fy]='d';
						print3(r,c);
					}
				}
			}
		}//cout<<endl;
	}
	return 0;
}



