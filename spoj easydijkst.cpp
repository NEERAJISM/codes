#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <queue>
using namespace std;
int main()
{
    int tt,n,e,i,a,b,c,k;
    scanf("%d",&tt);

    while(tt--)
    {
        scanf("%d%d",&n,&e);

        vector< vector < pair<int,int> > > v(n+2);

        for(i=0;i<e;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            v[a].push_back(make_pair(b,c));
        }

        scanf("%d%d",&a,&b);

        vector<int> dist(n+2,INT_MAX);
        dist[a] = 0;

        priority_queue< pair<int,int> > pq;
        pq.push(make_pair(0,a));

        while(1)
        {
            //cout<<"**\n";
            int nsrc = pq.top().second;
            int nwt = - pq.top().first;
            //cout<<nsrc<<" "<<nwt<<endl;
            if(nsrc == b)
            {
                printf("%d\n",nwt);
                break;
            }

            pq.pop();

            if(dist[nsrc] < nwt)
                continue;

            for(int j = 0;j<v[nsrc].size();j++)
            {
                //cout<<"**2\n";
                if(dist[v[nsrc][j].first] > dist[nsrc] + v[nsrc][j].second)
                {
                    dist[v[nsrc][j].first] = dist[nsrc] + v[nsrc][j].second;
                    pq.push(make_pair(-dist[v[nsrc][j].first],v[nsrc][j].first));
                }
            }
            if(pq.empty()==1)
            {
                printf("NO\n");
                break;
            }
        }
    }
return 0;
}
