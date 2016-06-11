#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
stack<int> s;
int mflag;
void topology(int i,vector<bool>& visited, vector< vector<int> >& v,int parent)
{
    if(mflag==1)
        return;
    visited[i] = true;
    for(int j=0;j<v[i].size();j++)
    {
        if(visited[v[i][j]] == false)
            topology(v[i][j],visited,v,i);

        if(v[i][j]==parent)
        {
            mflag=1;
            return;
        }
    }
    s.push(i);
}

int main()
{
    int n,m,i,j,x,y;
    scanf("%d%d",&n,&m);
    vector< vector<int> > v(n+2);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }

    vector<bool> visited(n+2,false);

    for(i=n;i>=1;i--)
    {
        if(visited[i] == false)
        {
            topology(i,visited,v,-1);
        }

        if(mflag==1)
            break;
    }

    if(mflag==1)
    {
        printf("Sandro fails\n");
    }
    else
        while(s.empty()==0)
        {
            printf("%d ",s.top());
            s.pop();
        }

return 0;
}
