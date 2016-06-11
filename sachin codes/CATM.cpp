#include<bits/stdc++.h>
using namespace std;

int g[102][102];
int mouse[102][102],cat1[102][102],cat2[102][102];

void bfs1(int n,int m,int startx,int starty)
{
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
	g[startx][starty]=1;
	mouse[startx][starty]=0;

	int curr_neigh_x,curr_neigh_y;
	
	while(!(q.empty()))
	{                             
		int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();//cout<<curr_ver_x<<"   "<<curr_ver_y<<endl;
		
		//if(curr_ver_x==1||curr_ver_x==m||curr_ver_y==1||curr_ver_y==n)
		//break;
		//else
		//{
			curr_neigh_x=(curr_ver_x)+1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				mouse[curr_neigh_x][curr_neigh_y]=mouse[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)+1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				mouse[curr_neigh_x][curr_neigh_y]=mouse[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x)-1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				mouse[curr_neigh_x][curr_neigh_y]=mouse[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)-1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				mouse[curr_neigh_x][curr_neigh_y]=mouse[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
	//	}
	}
}

void bfs2(int n,int m,int startx,int starty)
{
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
	g[startx][starty]=1;
	cat1[startx][starty]=0;
	int k=1;
	int curr_neigh_x,curr_neigh_y;
	
	while(!(q.empty()))
	{                                   
		int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();
		
		//if(curr_ver_x==1||curr_ver_x==m||curr_ver_y==1||curr_ver_y==n)
		//break;
		
			curr_neigh_x=(curr_ver_x)+1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				cat1[curr_neigh_x][curr_neigh_y]=cat1[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)+1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				cat1[curr_neigh_x][curr_neigh_y]=cat1[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x)-1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				cat1[curr_neigh_x][curr_neigh_y]=cat1[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)-1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				cat1[curr_neigh_x][curr_neigh_y]=cat1[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
		
	}
}

void bfs3(int n,int m,int startx,int starty)
{
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
	g[startx][starty]=1;
	cat2[startx][starty]=0;

	int curr_neigh_x,curr_neigh_y;
	
	while(!(q.empty()))
	{                                
		int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();//cout<<curr_ver_x<<"   "<<curr_ver_y<<endl;
		
		//if(curr_ver_x==1||curr_ver_x==m||curr_ver_y==1||curr_ver_y==n)
		//break;
		
			curr_neigh_x=(curr_ver_x)+1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				cat2[curr_neigh_x][curr_neigh_y]=cat2[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)+1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				cat2[curr_neigh_x][curr_neigh_y]=cat2[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x)-1;
			curr_neigh_y=curr_ver_y;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				cat2[curr_neigh_x][curr_neigh_y]=cat2[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
			
			curr_neigh_x=(curr_ver_x);
			curr_neigh_y=(curr_ver_y)-1;
			if(curr_neigh_x<=n&&curr_neigh_x>=1&&curr_neigh_y<=m&&curr_neigh_y>=1&&g[curr_neigh_x][curr_neigh_y]==0)
			{
				g[curr_neigh_x][curr_neigh_y]=1;
				cat2[curr_neigh_x][curr_neigh_y]=cat2[curr_ver_x][curr_ver_y]+1;
				q.push(make_pair(curr_neigh_x,curr_neigh_y));
			}
		
	}
}


int main()
{
	int t,n,m,i,j,m1,m2,c11,c12,c21,c22;
	scanf("%d%d",&n,&m);

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d",&m1,&m2,&c11,&c12,&c21,&c22);
		
		for(i=0;i<102;i++)
		{
			for(j=0;j<102;j++)
			{
				g[i][j]=0;
				mouse[i][j]=-1;
				cat1[i][j]=100002;
				cat2[i][j]=100003;
			}
		}
		
		bfs1(n,m,m1,m2);
		
		for(i=1;i<=101;i++)
		for(j=1;j<=101;j++)
		g[i][j]=0;
		//cout<<"now"<<endl;
		bfs2(n,m,c11,c12);
		
		for(i=1;i<=101;i++)
		for(j=1;j<=101;j++)
		g[i][j]=0;
		
		bfs3(n,m,c21,c22);
		
		
		/*for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cout<<mouse[i][j]<<"    ";				
			}
			cout<<endl;
		}*/
		
	
				int flag=0;
				for(i=1;i<=n;i++)
				{
					if((mouse[i][1]<cat1[i][1])&&(mouse[i][1]<cat2[i][1]))
					flag=1;
					if((mouse[i][m]<cat1[i][m])&&(mouse[i][m]<cat2[i][m]))
					flag=1;
				}
				for(j=1;j<=m;j++)
				{
					if((mouse[1][j]<cat1[1][j])&&(mouse[1][j]<cat2[1][j]))
					flag=1;
					if((mouse[n][j]<cat1[n][j])&&(mouse[n][j]<cat2[n][j]))
					flag=1;
				}
				if(flag==1)
				printf("YES\n");
				else
				printf("NO\n");
		

	}
	return 0;
}
