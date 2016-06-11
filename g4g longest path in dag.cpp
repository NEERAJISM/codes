#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

void topology(int i,vector< vector< pair<int,int> > >& v, vector<bool>& visited, stack<int>& stk)
{
    visited[i] = true;
    for(int j = 0;j<v[i].size();j++)
    {
        if( visited[v[i][j].first] == false )
        {
            topology(v[i][j].first,v,visited,stk);
        }
    }
    stk.push(i);
}

int main()
{
    int n,e,i,x,y,w;
    scanf("%d%d",&n,&e);
    vector< vector< pair<int,int> > > v(n+2);
    vector<bool> visited(n+2,false);
    stack<int> stk;
    vector<int> topresult(n+2);
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back(make_pair(y,w));
    }

    for(i=1;i<=n;i++)
    {
        if(visited[i]==false)
            topology(i,v,visited,stk);
    }

    i=1;
    while(stk.empty()==0)
    {
        topresult[i] = stk.top();
        i++;
        stk.pop();
    }

    cout<<"\nenter the source : ";
    int src;
    scanf("%d",&src);
    vector<int> dist(n+2,INT_MIN);

    dist[src] = 0;

    for(i=1;i<=n;i++)
    {
        for(int j=0;j<v[topresult[i]].size();j++)
        {
            if(dist[j]!= INT_MIN)
            if(dist[j]< dist[topresult[i]] + v[topresult[i]][j].second)
                dist[j] = dist[topresult[i]] + v[topresult[i]][j].second;
        }
    }

    for(i=1;i<=n;i++)
        cout<<dist[i]<<" ";

return 0;
}
/*
6 10
1 2 5
1 3 3
2 3 2
2 4 6
3 4 7
3 5 4
4 5 -1
4 6 1
5 6 -2
3 6 2

*/
