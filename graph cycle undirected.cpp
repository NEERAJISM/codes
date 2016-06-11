#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool dfs(int i,vector< vector<int> >& v, vector<bool>& visited ,int parent)
{
    visited[i] =true;
    for(int j=0;j<v[i].size();j++)
    {
        if(visited[v[i][j]]==false)
        {
            if(dfs(v[i][j],v,visited,i))
            return true;
        }
        else if(v[i][j] != parent)
            return true;
    }
    return false;
}

int main()
{
    int n,e,i,j,x,y;
    scanf("%d%d",&n,&e);

    vector< vector<int> > v(n+2);
    vector<bool> visited(n+2,false);

    for(i=0;i<e;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(i=1;i<=n;i++)
    {
        if(visited[i] == false)
        {
           bool result =  dfs(i,v,visited,-1);

           if(result == true)
           {
               cout<<"cycle!!!\n";
                break;
           }
           else
            cout<<" No cycle!!";
        }
    }
return 0;
}
