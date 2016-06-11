#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > g;
vector<bool> traversed;
vector<bool> started;
int a[3][100003];
int co,check;
//vector<int> distances;

int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

void dfs(int start,int G)
{
	traversed[start]=true;
	int count=0;        
	int curr_ver=start;                     
		for(int i=0;i<g[curr_ver].size();i++)
		{
			if(curr_ver==check)
			G=g[curr_ver][i].second;
			int curr_neigh=g[curr_ver][i].first;    int edge=g[curr_ver][i].second; 
			if(!traversed[curr_neigh])
			{
				traversed[curr_neigh]=true;
				//cout<<"G="<<G<<"edge="<<edge<<endl;
				int p=gcd(G,edge);
				if(p==1&&(!started[curr_neigh]))
				{
					co++;
					//cout<<"check="<<check<<"co="<<co<<"curr ver="<<curr_ver<<"neigh="<<curr_neigh<<endl;
				}
				dfs(curr_neigh,p);
			}
		}
}
int main()
{

	int i,j,u,v,w,n,m,source,sink,t,q,pos,val,ans;
	scanf("%d",&n);
	if(n==1)
    printf("0\n");
	else
	{
	
	g.resize(n+1);
	traversed.resize(n+1);
	started.resize(n+1);
	
	for(i=1;i<=n;i++)
	{
		traversed[i]=false;
		started[i]=false;
	}
	
	m=n-1;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		a[1][i]=u;   a[2][i]=v;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	
	ans=0;
	for(i=1;i<=n;i++)
	{
		co=0;   check=i;
		started[i]=true;
		dfs(i,g[i][0].second);
		for(j=1;j<=n;j++)
		traversed[j]=false;
		ans+=co;
		//cout<<"ans="<<ans<<endl;
	}
	printf("%d\n",ans);
	
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&pos,&val);
		
		for(i=1;i<=n;i++)
		{
			traversed[i]=false;
			started[i]=false;
		}
		
		u=a[1][pos];   v=a[2][pos];
		for(i=0;i<g[u].size();i++)
		{
			if(g[u][i].first==v)
			g[u][i].second=val;
		}
		for(i=0;i<g[v].size();i++)
		{
			if(g[v][i].first==u)
			g[v][i].second=val;
		}
		
		ans=0;
		for(i=1;i<=n;i++)
		{
			co=0;  check=i;
			started[i]=true;
			dfs(i,g[i][0].second);
			for(j=1;j<=n;j++)
			traversed[j]=false;
			ans+=co;
			//cout<<"ans="<<ans<<endl;
		}
		printf("%d\n",ans);
	}
}
	return 0;
}
