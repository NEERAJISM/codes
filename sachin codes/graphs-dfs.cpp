#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> colour(100);
vector<int> time_in(100);
vector<int> time_out(100);
int timer=0;

void dfs(int start)
{
	time_in[start]=timer++;
	colour[start]=1;//cout<<start<<"  ";
	for(int i=0;i<g[start].size();i++)
	{
		if(colour[g[start][i]]==0)
		dfs(g[start][i]);
	}
	colour[start]=2;
	time_out[start]=timer++;
}

int main()
{
/*	g.clear();
	colour.clear();
	time_in.clear();
	time_out.clear();
	*/
	int i,u,v,n,m,source,sink,t;
	scanf("%d%d",&n,&m);
	g.resize(n+1);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);

	return 0;
}
