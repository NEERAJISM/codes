#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int i,vector<bool>& visited,vector< vector<int> >& v,int parent)
{
    visited[i] =true;
    for(int j=0;j<v[i].size();j++)
    {
        if(visited[v[i][j]] == false && dfs(v[i][j],visited,v,i))
            return true;
        else if(v[i][j] == parent)
            return true;
    }
    return false;
}

int main()
{
    int i,j,n,e,x,y;
    scanf("%d%d",&n,&e);
    vector< vector<int>> v(n+2);

    for(i=0;i<e;i++)
    {
        scanf("%d%d",&x,&y);

        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<bool> visited(n+2,false);

    for(i=1;i<=n;i++)
    {
        if(visited[i] == false)
        {
            if(dfs(i,visited,v,-1))
                cout<<"cycle!!\n";
            else
                cout<<"no cycle!!\n";
        }
    }
return 0;
}
