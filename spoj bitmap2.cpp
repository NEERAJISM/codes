#include <iostream>
#include <cstdio>
#include <climits>
#include <queue>
using namespace std;
int n,m,a[183][183],b[183][183],ab[182][182];

void mark(queue< pair<int,int> > q1,int length)
{
    queue< pair<int,int> > q2;

    while(q1.empty()==0)
    {
        int x = q1.front().first;
        int y = q1.front().second;
        b[x][y] = length;
        q1.pop();

        if(x+1<=n)
        {
            if(a[x+1][y]!=1 &&ab[x+1][y] ==0 && length < b[x+1][y])
            {
                //cout<<x+1<<" "<<y<<endl;
                ab[x+1][y] =1;
                q2.push(make_pair(x+1,y));
            }
        }

        if(x-1>0)
        {
            if(a[x-1][y]!=1 && ab[x-1][y] ==0 && length < b[x-1][y])
            {
                //cout<<x-1<<" "<<y<<endl;
                ab[x-1][y] =1;
                q2.push(make_pair(x-1,y));
            }
        }

        if(y+1<=m)
        {
            if(a[x][y+1]!=1&&ab[x][y+1] ==0 && length < b[x][y+1])
            {
                //cout<<x<<" "<<y+1<<endl;
                ab[x][y+1] = 1;
                q2.push(make_pair(x,y+1));
            }
        }

        if(y-1>0)
        {
            if(a[x][y-1]!=1 && ab[x][y-1] ==0 && length < b[x][y-1])
            {
                //cout<<x<<" "<<y-1<<endl;
                ab[x][y-1] =1;
                q2.push(make_pair(x,y-1));
            }
        }
    }

    //cout<<"outside"<<endl;
    if(q2.empty()==0)
    {
        length++;
        mark(q2,length);
    }
}


int main()
{
    int tt,i,j,i1,j1;
    char temp;

    scanf("%d",&tt);

    while(tt--)
    {
        scanf("%d%d",&n,&m);

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                cin>>temp;
                a[i][j] = int(temp)  - int('0');
                b[i][j] = INT_MAX;
            }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]==1)
                {

                    for(i1=1;i1<=n;i1++)
                        for(j1=1;j1<=m;j1++)
                            ab[i1][j1] = 0;


                    queue< pair<int,int> > q;
                    q.push(make_pair(i,j));
                    ab[i][j] = 1;
                    //cout<<i<<" "<<j<<endl;
                    mark(q,0);
                }
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                printf("%d ",b[i][j]);

            printf("\n");
        }
    }
}
