#include <bits/stdc++.h>
using namespace std;
vector< vector <int> > v(100);
vector<int> vb(100,false);
stack<int> s;

void dfs(int src)
{
    vb[src] = true;

    int current =s.top();
    cout<<current<<" ";
    s.pop();

    for(int i=0;i<v[current].size();i++)
    {
        //cout<<v[current][i]<<"//"<<endl;
        if(vb[v[current][i]] == false)
        {
            s.push(v[current][i]);
            dfs(s.top());
        }
    }
}
int main()
{
    int n,i,e,x,y,src,j;
    scanf("%d%d",&n,&e);

    for(i=0;i<e;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }
    cout<<endl;

    for(i=1;i<=n;i++)
    {
        for(j=0;j<v[i].size();j++)
            printf("%d ",v[i][j]);

        cout<<endl;
    }

    //dfs
    scanf("%d",&src);
      s.push(src);
    dfs(src);
return 0;
}
/*

9
8
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
1

*/
