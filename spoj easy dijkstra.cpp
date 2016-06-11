#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i,j,a,b,c;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&k);

        vector< vector < pair <int,int> > > v(n+3);

        for(i=1;i<=k;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            v[a].push_back(make_pair(b,c));
        }

        scanf("%d%d",&a,&b);

        vector<int> dist(n+3,INT_MAX);
        dist[a] = 0;

        priority_queue< pair<int,int> > pq;
        pq.push(make_pair(0,a));

        int flag =0;
        while(pq.empty()==0)
        {
            int nsrc = (pq.top()).second;
            int nwt = -(pq.top()).first;

            if(nsrc == b)
            {
                printf("%d\n",nwt);
                flag =1;
                break;
            }

            pq.pop();

            if(nwt > dist[nsrc])
                continue;

            for(i=0;i<v[nsrc].size();i++)
            {
                if(nwt + v[nsrc][i].second < dist[v[nsrc][i].first])
                {
                    dist[v[nsrc][i].first] = nwt + v[nsrc][i].second ;
                    pq.push(make_pair(-dist[v[nsrc][i].first],v[nsrc][i].first));
                }
            }
        }

        if(flag==0 || pq.empty()==1)
        {
            printf("NO\n");
        }

    }
return 0;
}
