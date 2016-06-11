#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tt,n,e,i,x,y,src;
    scanf("%d",&tt);

    while(tt--)
    {
        scanf("%d%d",&n,&e);

        vector< vector<int> > v(n+2);

        for(i=0;i<e;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
        }

        scanf("%d",&src);

        queue<int> q;
        q.push(src);

        vector<bool> vb(n+2);
        vb[src] = true;

        vector<int> vd(n+2,-1);
        vd[src] = 0;
        int dist = 6;

        while(q.empty()==0)
        {
            for(int j= 0;j<v[q.front()].size();j++)
            {
                if(vb[v[q.front()][j]]==false)
                {
                    vb[v[q.front()][j]] = true;
                    q.push(v[q.front()][j]);
                    vd[v[q.front()][j]] = vd[q.front()]+6;
                }
            }
            q.pop();
        }

        for(i=1;i<=n;i++)
        {
            if(i!=src)
                printf("%d ",vd[i]);
        }
        cout<<endl;
    }
return 0;
}
