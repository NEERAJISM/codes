#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int ttt,n,e;

int main()
{
    int tt,i,j,x,y,clr,sflag;
    scanf("%d",&tt);
    ttt=1;
    while(ttt<=tt)
    {
        scanf("%d%d",&n,&e);
        vector< vector<int> > v(n+2);

        for(i=0;i<e;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }

        vector<bool> vb(n+2,false);
        vector<int> color(n+2,-2);
        queue<int> q;

        q.push(1);
        vb[1] = true;
        color[1] = 0;
        clr = 0;
        int mflag = 0;

        while(1)
        {
            while(q.empty() == 0)
            {
                clr=(clr+1)%2;

                /*for(i=1;i<=n;i++)
                    cout<<color[i]<<" ";

                cout<<endl;*/

                queue<int> q2;
                while(q.empty()==0)
                {

                    for(i=0;i<v[q.front()].size();i++)
                    {
                        if(vb[v[q.front()][i]] ==  true  && color[v[q.front()][i]] == (clr+1)%2)
                        {
                            mflag=1;
                            break;
                        }

                        if(vb[v[q.front()][i]] ==  false)
                        {
                            //cout<<v[q.front()][i]<<"**"<<clr<<endl;
                            color[v[q.front()][i]] = clr;
                            vb[v[q.front()][i]] = true;
                            q2.push(v[q.front()][i]);
                        }
                    }
                    q.pop();
                    if(mflag==1)
                    break;
                }
                q= q2;
                if(mflag==1)
                    break;
            }

            if(mflag==1)
                break;

            sflag= 0;

            for(i=1;i<=n;i++)
            {
                if(vb[i]==false)
                {
                    sflag=1;
                    break;
                }
            }

            if(sflag==0)
                break;
            else
            {
                q.push(i);
                vb[i] = true;
                color[i] = 0;
                clr = 0;
                int mflag = 0;
            }
        }

        if(mflag==1)
            printf("Scenario #%d:\nSuspicious bugs found!\n",ttt);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n",ttt);

        ttt++;
    }
}
