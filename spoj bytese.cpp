#include <iostream>
#include <cstdio>
#define max1 214748364
using namespace std;
int a[101][101];
int travel(int x0,int y0,int x1,int y1,int m,int n,int bull[101][101])
{
    bull[x0][y0] =1;

    if(x0==x1 && y0==y1)
    {
        bull[x0][y0] =0;
        return a[x0][y0];
    }
    else
    {
        int up = max1,down=max1,left=max1,right=max1;

        if(y0-1>=1 && bull[x0][y0-1] ==0)
            up = a[x0][y0]+travel(x0,y0-1,x1,y1,m,n,bull);

        if(y0+1<=n&& bull[x0][y0+1] ==0)
            down = a[x0][y0]+travel(x0,y0+1,x1,y1,m,n,bull);

        if(x0+1<=m&& bull[x0+1][y0] ==0)
            right = a[x0][y0]+travel(x0+1,y0,x1,y1,m,n,bull);

        if(x0-1>=1&& bull[x0-1][y0] ==0)
            left = a[x0][y0]+travel(x0-1,y0,x1,y1,m,n,bull);

        up = up<down?up:down;
        right = right<left?right:left;
        right = right<up?right:up;

        bull[x0][y0] = 0;
        return right;
    }
}

int main()
{
    int t,m,n,i,j,a1,b,k,tym,bull[101][101];
    scanf("%d",&k);

    while(k--)
    {
        scanf("%d%d",&m,&n);
        for(i=1 ; i<=m ; i++)
            for(j=1 ; j<=n ; j++)
            {
                scanf("%d",&a[i][j]);
                bull[i][j]=0;
            }

        scanf("%d%d%d",&a1,&b,&t);

        tym = travel(1,1,a1,b,m,n,bull);

        if(t>=tym)
            printf("YES\n%d\n",t-tym);
        else
            printf("NO\n");
    }
    return 0;
}
