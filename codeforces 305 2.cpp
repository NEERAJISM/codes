#include <bits/stdc++.h>
using namespace std;
int n,m,q,a[501][501],b[501],x,y,high;

int maxpattern(int r)
{

    int max1 = 0,sum;

    for(int j= 1;j<=m ; j++)
    {
        if(a[r][j]==1)
        {
            sum =1;
            j++;

            while(1)
            {
                if( j<=m && a[r][j] == 1)
                {
                    sum++;
                    j++;
                }
                else
                    break;
            }
            if(sum > max1)
                max1 = sum;
        }
    }
    return max1;
}

int main()
{
    cin>>n>>m>>q;

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
            cin>>a[i][j];

    for(int i=1 ; i <= n ; i++)
        b[i] = maxpattern(i);

    for(int i=1 ;i<= q ;i++)
    {
        cin>>x>>y;

        if(a[x][y]==0)
            a[x][y] =1;
        else
            a[x][y] =0;

        b[x] = maxpattern(x);

        high = 0;

        for(int j=1 ; j <=n ; j++)
            if(b[j] > high)
                high = b[j];

        cout<<high<<endl;
    }
    return 0;
}
