#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,a1;
char v[185][185];
int vans[185][185];
int flag;
int alpha[185][185];
//queue<pair<int,int>>::iterator it;
void markall(queue< pair <int,int> > q,int length)
{
    int x,y;

    queue< pair <int,int> > q2;
    while(q.empty()!=1)
    {
        x= (q.front()).first;
        y= (q.front()).second;

        vans[x][y] = length;


        if(x+1 < n && v[x+1][y]=='0' && alpha[x+1][y] == 0 && vans[x+1][y] > length)
            q2.push(make_pair(x+1,y));

        if(x-1 > -1 && v[x-1][y]=='0' && alpha[x-1][y] == 0 && vans[x-1][y] > length)
            q2.push(make_pair(x-1,y));

        if(y+1 < m && v[x][y+1]=='0' && alpha[x][y+1] == 0 && vans[x][y+1] > length)
            q2.push(make_pair(x,y+1));

        if(y-1 > -1 && v[x][y-1]=='0' && alpha[x][y-1] == 0 && vans[x][y-1] > length)
            q2.push(make_pair(x,y-1));

        q.pop();
    }

    if(q2.empty()==0)
    {
        length++;
        markall(q2,length);
    }
}

int main()
{
   scanf("%d",&t);
    while(t--)
    {
        a1=0;
        scanf("%d%d",&n,&m);

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                vans[i][j] = 1000;


        for(i=0;i<n;i++)
            scanf("%s",v[i]);

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(v[i][j]=='1')
                {
                    int alpha[185][185];

                    for(int i1=0;i1<n;i1++)
                        for(int j1=0;j1<m;j1++)
                            alpha[i1][j1] = 0;

                    int length = 0;
                    flag=0;

                    queue< pair <int,int> > q;
                    q.push(make_pair(i,j));
                    markall(q,length);
                }
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                printf("%d ",vans[i][j]);
            cout<<endl;
        }
    }
return 0;
}
