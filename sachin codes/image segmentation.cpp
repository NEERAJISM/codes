#include<bits/stdc++.h>
using namespace std;

char g[1002][1002];
int visited[1002][1002];
int ans[1000003];
int k;

void bfs(int h,int w,int startx,int starty)
{
	queue< pair<int,int> > q;
	q.push(make_pair(startx,starty));
    visited[startx][starty]=1;
    //cout<<endl<<endl<<"hello"<<endl;
    int curr_neigh_x,curr_neigh_y;
    int c=0;
    
    while(!(q.empty()))
    {
    	int curr_ver_x=q.front().first;	int curr_ver_y=q.front().second;
		q.pop();
		c++;  //cout<<curr_ver_x<<"  "<<curr_ver_y<<endl;
		
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=curr_ver_y;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]=='#')
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		
		curr_neigh_x=(curr_ver_x);
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]=='#')
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=curr_ver_y;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]=='#')
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		
		curr_neigh_x=(curr_ver_x);
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]=='#')
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]=='#')
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]=='#')
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		
		curr_neigh_x=(curr_ver_x)+1;
		curr_neigh_y=(curr_ver_y)-1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]=='#')
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
		
		curr_neigh_x=(curr_ver_x)-1;
		curr_neigh_y=(curr_ver_y)+1;
		if(curr_neigh_x<=h&&curr_neigh_x>=1&&curr_neigh_y<=w&&curr_neigh_y>=1&&visited[curr_neigh_x][curr_neigh_y]==0&&g[curr_neigh_x][curr_neigh_y]=='#')
		{
			visited[curr_neigh_x][curr_neigh_y]=1;
			q.push(make_pair(curr_neigh_x,curr_neigh_y));
		}
    }
    ans[k++]=c;
}


int main()
{
	int t,h,w,i,j;
	string s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&w);
		//cin.ignore();
		k=0;
		memset(visited,0,sizeof(visited));
		
		for(i=1;i<=h;i++)
		{
			cin>>s;
			int l=(int)(s.size());
			for(j=1;j<=l;j++)
			{
				g[i][j]=s[j-1];
			}
		}
		
		int count=0;
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				if(!visited[i][j]&&g[i][j]=='#')
				{
					count++;
					bfs(h,w,i,j);
				}
			}
		}
		
		printf("%d\n",count);
		
		sort(ans,ans+k);
		for(i=0;i<k;i++)
		cout<<ans[i]<<" ";
		
		cout<<endl;
	}
	return 0;
}
