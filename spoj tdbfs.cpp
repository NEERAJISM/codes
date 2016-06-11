#include <bits/stdc++.h>
using namespace std;
int a[101][101],i1=1,i,j,n,t,i2,m,q1,q2,src,temp;

void dfs(int src)
{
    vector<int> b(101,0);
    stack<int> s;
    s.push(src);
    b[src]=1;
    int count = 1;
    //cout<<src<<" ";

    while(s.empty() !=1)
    {
        temp = s.top();
        cout<<s.top()<<" ";
        s.pop();

        for(int i = 0;i<a[temp][0];i++)
        {
            if(b[a[temp][i+1]] == 0)
            {
                s.push(a[temp][i+1]) ;
                b[a[temp][i+1]] = 1 ;
            }
        }
    }
    b.clear();
    cout<<endl;
}

void bfs(int src)
{
    vector<int> b(101,0);
    queue<int> q;
    q.push(src);
    b[src]=1;
    int count;

    while(q.empty() !=1)
    {
        for(int i = 0;i<a[q.front()][0];i++)
        {
            if(b[a[q.front()][i+1]] == 0)
            {
                q.push(a[q.front()][i+1]) ;
                b[a[q.front()][i+1]] = 1 ;
            }
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    b.clear();
    cout<<endl;
}

int main()
{
    cin>>t;
    while(i1<=t)
    {
        cin>>n;

        for(i=1;i<=n;i++)
        {
            cin>>i2>>m;
            a[i2][0]=m;
            if(m==0)
                a[i2][1]=0;
            else
                for(j=1;j<=m;j++)            //adjacent nodes are inserted  from 0
                    cin>>a[i2][j];
        }

        cout<<endl;

        cout<<"graph "<<i1<<endl;

        while(1)
        {
            cin>>q1>>q2;

            if(q1==0 && q2==0)
                break;
            else
            {
                src = q1;
                if(q2==0)       //dfs
                {
                    dfs(src);
                }
                else            //bfs
                {
                    bfs(src);
                }
            }
        }
    }
    return 0;
}
