#include <bits/stdc++.h>
using namespace std;
int m,n,a[105][105],t,xi,yi,b[105][105],length;
void dijkstra(int x,int y)
{
    b[x][y] = a[1][1];
    priority_queue< pair< int , pair <int,int> > > pq;
    pq.push(make_pair(-a[1][1],make_pair(1,1)));

    while(1)
    {
        int nsrcx = pq.top().second.first;
        int nsrcy = pq.top().second.second;
        int nwt = - pq.top().first;

        //cout<<nsrcx<<" "<<nsrcy<<" "<<nwt<<endl;

        if(nsrcx== xi && nsrcy == yi)
        {
            nwt = t-nwt;
            if(nwt >=0)
                printf("YES\n%d\n",nwt);
            else
                printf("NO\n");

            break;
        }

        pq.pop();

        if(b[nsrcx][nsrcy] > nwt)
        {
            continue;
        }
        if(nsrcx+1<=m )
        {
            //cout<<"down\n";
            if(b[nsrcx+1][nsrcy] > nwt + a[nsrcx+1][nsrcy])
            {
                b[nsrcx+1][nsrcy] = nwt + a[nsrcx+1][nsrcy];
                pq.push(make_pair(-b[nsrcx+1][nsrcy],make_pair(nsrcx+1,nsrcy)));
            }
        }

        if(nsrcx-1>0 )
        {
                //cout<<"up\n";
            if(b[nsrcx-1][nsrcy] > nwt + a[nsrcx-1][nsrcy])
            {
                b[nsrcx-1][nsrcy] = nwt + a[nsrcx-1][nsrcy];
                pq.push(make_pair(-b[nsrcx-1][nsrcy],make_pair(nsrcx-1,nsrcy)));
            }
        }

        if(nsrcy+1<=n)
        {
            //cout<<"right\n";
            if(b[nsrcx][nsrcy+1] > nwt + a[nsrcx][nsrcy+1])
            {
                b[nsrcx][nsrcy+1] = nwt + a[nsrcx][nsrcy+1];
                pq.push(make_pair(-b[nsrcx][nsrcy+1],make_pair(nsrcx,nsrcy+1)));
            }
        }
        //cout<<"y-1 ="<<nsrcy-1<<endl;
        if(nsrcy-1>0)
        {
            //cout<<"left\n";
            if(b[nsrcx][nsrcy-1] > nwt + a[nsrcx][nsrcy-1])
            {
                b[nsrcx][nsrcy-1] = nwt + a[nsrcx][nsrcy-1];
                pq.push(make_pair(-b[nsrcx][nsrcy-1],make_pair(nsrcx,nsrcy-1)));
            }
        }
    }
}

int main()
{
    int tt,i,j,k;
    scanf("%d",&tt);

    while(tt--)
    {
        scanf("%d%d",&m,&n);

        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                b[i][j]=INT_MAX;
            }

        scanf("%d%d%d",&xi,&yi,&t);

        dijkstra(1,1);
    }
return 0;
}
