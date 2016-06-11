#include <iostream>
#include <cstdio>
using namespace std;
int a[100000];
bool flag;

bool issubsetsum(int n,int m)
{
    bool sum[m+1][n+1];

    for(int i = 0;i<=n;i++)
        sum[0][i] = true;

    for(int i = 1;i<=m;i++)
        sum[i][0] = false;

    for(int i=1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            sum[i][j] = sum[i][j-1];

            if(i>=a[j-1])
            {
                sum[i][j] = sum[i][j] || sum[i-a[j-1]][j-1];
            }
        }
    }

return sum[m][n];
}

int main()
{
    int t,n,m,i;
    scanf("%d",&t);

    while(t--)
    {

        scanf("%d%d",&n,&m);

        for(i = 0;i<n;i++)
            scanf("%d",&a[i]);

        flag = issubsetsum(n,m);

        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
