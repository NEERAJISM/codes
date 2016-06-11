#include <iostream>
#include <cstdio>
using namespace std;
char v[183][183];
int vans[200][200],n,m,alpha[200][200];

void markall(int q[][2],int qadd1,int length)
{
    int x,y,q2[183][2],qadd2=-1;

    while(qadd1 > -1)
    {
        x= q[qadd1][0];
        y= q[qadd1][1];
        qadd1--;

        vans[x][y] = length;

        if(x+1 < n)
        {
            if(v[x+1][y]=='0' && alpha[x+1][y] == 0 && vans[x+1][y] > length)
            {
                qadd2++;
                q2[qadd2][0] =x+1 ;
                q2[qadd2][1] =y;
            }
        }

        if(x-1 > -1 )
        {
            if(v[x-1][y]=='0' && alpha[x-1][y] == 0 && vans[x-1][y] > length)
            {
                qadd2++;
                q2[qadd2][0] =x-1 ;
                q2[qadd2][1] =y;
            }
        }

        if(y+1 < m )
        {
            if( v[x][y+1]=='0'&& alpha[x][y+1] == 0 && vans[x][y+1] > length)
            {
                qadd2++;
                q2[qadd2][0] =x ;
                q2[qadd2][1] =y+1;
            }
        }

        if(y-1 > -1 && alpha[x][y-1] == 0 && vans[x][y-1] > length)
        {
            if(v[x][y-1]=='0')
            {
                qadd2++;
                q2[qadd2][0] =x ;
                q2[qadd2][1] =y-1;
            }
        }
    }

    if(qadd2>-1)
    {
        length++;
        markall(q2,qadd2,length);
    }
}

int main()
{
    int t,i,j,i1,j1,length;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
               cin>>v[i][j];

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                vans[i][j] = 1000000;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(v[i][j]=='1')
                {
                    for(i1=0;i1<n;i1++)
                        for(j1=0;j1<m;j1++)
                            alpha[i1][j1] = 0;

                    length = 0;
                    int q[183][2],qadd1 = 0;
                    q[qadd1][0] = i;
                    q[qadd1][1] = j;
                    markall(q,qadd1,length);
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
