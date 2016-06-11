#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> traversed(100);
vector<int> parent(100);
vector<int> distances(100);

void bfs(int n,int start)
{
	queue<int> q;
	q.push(start);
	traversed[start]=true;
	parent[start]=-1;
	distances[start]=0;
	
	while(!(q.empty()))
	{                                
		int curr_ver=q.front();
		q.pop();
		for(int i=0;i<g[curr_ver].size();i++)
		{
			int curr_neigh=g[curr_ver][i];
			if(!traversed[curr_neigh])
			{
				traversed[curr_neigh]=true;
				q.push(curr_neigh);
				distances[curr_neigh]=distances[curr_ver]+1;
				parent[curr_neigh]=curr_ver;
			}
		}
	}
}
void check_path(int n,int source,int sink)
{
	bfs(n,source);
	
	if(!traversed[sink])
	printf("no path\n");
	else
	{
		vector<int> path;
		for(int v=sink;v!=-1;v=parent[v])
		path.push_back(v);
		
		reverse(path.begin(),path.end());
		printf("path =  ");
		for(int i=0;i<path.size();i++)
		cout<<path[i]<<"  ";
		cout<<endl;
		
		cout<<"distance= "<<distances[sink]<<endl;
	}
}

int main()
{
/*	g.clear();
	traversed.clear();
	parent.clear();
	distances.clear();
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
	cout<<"enter the number of checks\n";
	cin>>t;
	while(t--){
	cout<<"enter the source and destination to check for path\n";
	cin>>source>>sink;
	check_path(n,source,sink);
}
	return 0;
}
