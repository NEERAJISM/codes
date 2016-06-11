#include <bits/stdc++.h>
#define mx 1000000007
using namespace std;
int main()
{
    int i,j,k,n,m,ttt,ti,x,y,z,w;
    scanf("%d",&ttt);

    while(ttt--)
    {
        scanf("%d%d%d",&n,&m,&ti);
        vector<vector<int> > v1(n+1,vector<int>(n+1,mx));
        vector<vector<int> > v2(n+1,vector<int>(n+1,mx));

        for(i=1;i<=n;i++)
        {
            v1[i][i] = 0;
            v2[i][i] = 0;
        }

        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&x,&y,&z,&w);

            v1[x][y] = z;
            v1[y][x] = z;
            v2[x][y] = w;
            v2[y][x] = w;
        }

        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(v1[i][k] + v1[k][j] < v1[i][j])
                        v1[i][j] = v1[i][k] + v1[k][j];

                    if(v2[i][k] + v2[k][j] < v2[i][j])
                        v2[i][j] = v2[i][k] + v2[k][j];
                }
    }
    return 0;
}
