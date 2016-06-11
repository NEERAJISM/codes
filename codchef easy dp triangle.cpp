#include <iostream>
#include <cstdio>
using namespace std;
int totsum[101][101];

int dpsum(int a[][101],int n)
{
    int temp;
        totsum[1][1] = a[1][1];

        for(int i=2;i<=n;i++)
            totsum[i][1] = a[i][1]+totsum[i-1][1];

        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=i;j++)
            {
                if(i-1<j)
                    temp = totsum[i-1][j-1];
                else
                {
                    temp = totsum[i-1][j-1]>totsum[i-1][j]?totsum[i-1][j-1]:totsum[i-1][j];
                }
                totsum[i][j] = a[i][j] + temp;
            }
        }

        int max1 = -1;
        for(int i=1;i<=n;i++)
        {
             if(max1<totsum[n][i])
                max1 = totsum[n][i];
        }
        return max1;
}

int main()
{
    int t,i,j,n,a[101][101],sum;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
                scanf("%d",&a[i][j]);

        cout<<dpsum(a,n)<<endl;
    }
}
