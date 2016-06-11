#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<vector<int> >gt;
vector<bool> visited;
vector<int> order;
vector<int> strong_component;

void make_unvisited(int n)
{
    for(int i=0;i<=n;i++)
    visited[i]=false;
}

void print_it(int x)
{
    cout<<"strongly connected component no="<<x<<endl;
    for(int i=0;i<strong_component.size();i++)
    {
        cout<<strong_component[i]<<"   ";
    }
    cout<<endl;
}

void dfs(int start)
{
    int v=start;
    visited[v]=true;
    
    for(int i=0;i<g[v].size();i++)
    {
        int neigh=g[v][i];
        if(!visited[neigh])
        dfs(neigh);
    }
    order.push_back(v);
}

void dfs2(int start)
{
    int v=start;
    visited[v]=true;
    strong_component.push_back(v);
    
    for(int i=0;i<gt[v].size();i++)
    {
        int neigh=gt[v][i];
        if(!visited[neigh])
        dfs2(neigh);
    }
}

int main()
{
    int i,j,n,m,x,y;
    cout<<"enter the number of vertices and edges\n";
    cin>>n>>m;
    
    g.clear();
    gt.clear();
    visited.clear();
    g.resize(n+1);
    gt.resize(n+1);
    visited.resize(n+1);
    
    cout<<"enter the edges\n";
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        gt[y].push_back(x);
    }
    
    make_unvisited(n);
    
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        dfs(i);
    }
    
    cout<<"here is the topological order\n";
    for(i=0;i<order.size();i++)
    cout<<order[i]<<"  ";
    cout<<endl;
    
    make_unvisited(n);
    
    int count=0;
    for(i=order.size()-1;i>=0;i--)
    {
        int v=order[i];
        if(!visited[v])
        {
            strong_component.clear();
            dfs2(v);
            count++;
            print_it(count);
        }
    }
    cout<<"total count="<<count<<endl;
}
