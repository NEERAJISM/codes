#include <bits/stdc++.h>
using namespace std;
map<string,int> mymap;
int main()
{
    int t,n,i,j,p,index,cost,src,dst,queries,boolean[10005],dist[10005],mini;
    char name[25],city1[25],city2[25];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        vector< vector < pair<int,int > > > v(n+3);

        for(i=1;i<=n;i++)
        {
            scanf("%s%d",name,&p);
            mymap.insert(make_pair(name,i));

            for(j=0;j<p;j++)
            {
                scanf("%d%d",&index,&cost);
                v[i].push_back(make_pair(index,cost));
            }
        }
        scanf("%d",&queries);
        for(i=0;i<queries;i++)
        {
            scanf("%s%s",city1,city2);

            src = mymap.find(city1)->second;
            dst = mymap.find(city2)->second;

            vector<int> dist(n+3,INT_MAX);
            dist[src] = 0;
            priority_queue< pair<int,int> > pq;
            pq.push(make_pair(0,src));

            while(1)
            {
                int nsrc = (pq.top()).second;
                int nwt = -(pq.top()).first;

                if(nsrc == dst)
                {
                    printf("%d\n",nwt);
                    break;
                }
                pq.pop();

                if(dist[nsrc] < nwt)
                    continue;

                for(int i1= 0;i1<v[nsrc].size();i1++)
                {
                    int vnode = v[nsrc][i1].first;
                    int vcost = v[nsrc][i1].second;

                    if(nwt + vcost < dist[vnode])
                    {
                        dist[vnode] = nwt + vcost;
                        pq.push(make_pair(-dist[vnode],vnode));
                    }
                }
            }
        }
    }
return 0;
}
