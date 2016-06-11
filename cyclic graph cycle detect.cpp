#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool detect(int i,vector< vector<int> >& v,vector<bool>& visited, vector<bool>& stk)
{
    visited[i] =true;
    stk[i] = true;

    for(int j=0;j<v[i].size();j++)
    {
        if(visited[v[i][j]] == false && detect(v[i][j],v,visited,stk))
            return true;
        else if(stk[v[i][j]] == true)
            return true;
    }

    stk[i] =false;
    return false;
}
int main()
{
    int n,e,i,x,y;

    scanf("%d%d",&n,&e);

    vector< vector<int> > v(n+2);
    vector<bool> visited(n+2,false);
    vector<bool> stk(n+2,false);

    for(i=0;i<e;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }

    for(i=1;i<=n;i++)
    {
        if(visited[i] == false)
        {
            if(detect(i,v,visited,stk))
            {
                cout<<"cycle\n";
                break;
            }

            else
                cout<<"no cycle\n";
        }
    }
return 0;
}
