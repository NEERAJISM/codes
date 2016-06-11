#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,b[501],a[501][2],x,y,bul[501],k,flag;
    memset(b,0,sizeof(b));
    memset(bul,0,sizeof(bul));
    vector<vector<int> > ind(501,vector<int>(2,0));
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);

            if(a[i][j] == n-1)
            {
                b[i] = n;
                b[j] = n-1;
                bul[n] = 1;
                bul[n-1] = 1;
            }
        }
    }

    for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            if(bul[a[i][j]] == 0)
            {
                flag = 0;
                for(k=i+1;k<=n;k++)
                {
                    if(a[k][j] == a[i][j])
                    {
                        bul[a[i][j]] = 1;
                        b[j] = a[i][j];
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0)
                {
                    bul[a[i][j]] = 1;
                    b[i] = a[i][j];
                }
            }
        }
    }

    for(i=1;i<=n;i++)
        printf("%d ",b[i]);
    return 0;
}
