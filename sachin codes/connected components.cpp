#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> colour(100);
vector<int> time_in(100);
vector<int> time_out(100);
vector<int> comp;
int timer=0;

void dfs(int start)
{
	time_in[start]=timer++;
	colour[start]=1;//cout<<start<<"  ";
	comp.push_back(start);
	for(int i=0;i<g[start].size();i++)
	{
		if(colour[g[start][i]]==0)
		dfs(g[start][i]);
	}
	colour[start]=2;
	time_out[start]=timer++;
}
int find_components(int n)
{
	for(int i=0;i<n;i++)
	colour[i]=0;

	int count=0;
	for(int i=1;i<n;i++)
	{
		if(colour[i]==0)
		{
			count++;
			comp.clear();
			dfs(i);
			for(int j=0;j<comp.size();j++)
			cout<<comp[j]<<"  ";
			cout<<endl;
		}
		
	}
	return count;
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
	int count=find_components(n);
	cout<<"no of connected components are  "<<count;
	return 0;
}
