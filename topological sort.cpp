#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

vector< vector<int> > v(100);
vector<bool> visited(100,false);
stack<int> stk;
void topologicalsort(int i)
{
    visited[i] =true;

    for(int j = 0;j<v[i].size();j++)
    {
        if(visited[v[i][j]] == false)
            topologicalsort(v[i][j]);
    }

    stk.push(i);
}

int main()
{
    int i,n,e,j,x,y;

    scanf("%d%d",&n,&e);
    //diracted graph
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }

    for(i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            //cout<<"first node "<<i<<endl;
            topologicalsort(i);
        }
    }

    while(stk.empty()==0)
    {
        cout<<stk.top()<<"*";
        stk.pop();
    }
return 0;
}
