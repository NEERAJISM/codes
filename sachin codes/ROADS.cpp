#include<bits/stdc++.h>
using namespace std;
#define maxn 1000001

int n,K,total_len,total_money;

vector<vector<pair<int,pair<int,int> > > > g;
int visited[102];
int count_vis[102];

void dfs(int ver,int l,int toll)
{
	//cout<<"ver="<<ver<<endl;
	if(l>total_len)
	return ;
	if(toll>K)
	return ;
	if(ver==n)
	{
		//cout<<"hi"<<total_money<<endl;
		if(l<total_len)
		{
			total_len=l;
			total_money=toll;
		}
		else if(l==total_len&&toll<total_money)
		total_money=toll;
		return ;
	}
	else
	{
		for(int i=0;i<g[ver].size();i++)
		{
			int neigh=g[ver][i].first;   int length=g[ver][i].second.first;    int money=g[ver][i].second.second;
			
				if(visited[neigh]==0)
				{
					visited[neigh]=1;
					count_vis[neigh]++;
					dfs(neigh,l+length,toll+money);
					if(count_vis[neigh]<=3000000)
					visited[neigh]=0;
				}
			
		}
    }
}

int main()
{
	int i,j,t,R,u,v,l,toll;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&K,&n,&R);
		g.clear();
		g.resize(n+2);
		for(i=1;i<=R;i++)
		{
			scanf("%d%d%d%d",&u,&v,&l,&toll);
			if(u!=v)
			g[u].push_back(make_pair(v,make_pair(l,toll)));
		}
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
			count_vis[i]=0;
		}
		
		visited[1]=1;
		
		total_len=maxn; total_money=maxn;
		
		dfs(1,0,0);
		
		if(total_money>K)
		printf("-1\n");
		else
		printf("%d\n",total_len);      //cout<<"mon"<<total_money<<endl;
	}
	return 0;
}
