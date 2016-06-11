#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> colour(100);
vector<int> time_in(100);
vector<int> time_out(100);
vector<int> ans;
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
	time_out[start]=timer++;//cout<<"vertex="<<start<<endl;
	ans.push_back(start);
	
}

void topological_sort(int n)
{
	for(int i=0;i<n;i++)
	colour[i]=0;

	ans.clear();
	for(int i=1;i<n;i++)
	{
		if(colour[i]==0)
		dfs(i);
	}
	reverse(ans.begin(),ans.end());
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
		//g[v].push_back(u);      because it is a directed graph; 
	}
	topological_sort(n);
	for(i=0;i<ans.size();i++)
	cout<<ans[i]<<"   ";
	cout<<endl;
	
	return 0;
}
