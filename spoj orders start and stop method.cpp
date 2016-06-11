#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ttt,i,j,n,v[200005],self[200005],d,vtr;
    scanf("%d",&ttt);

    while(ttt--)
    {
        scanf("%d",&n);
        memset(v,0,n+5);
        memset(self,0,n+5);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&d);

            if(d>0)
            {
                self[i] = d;
                v[i] = -1;
                v[i-d] += 1;
            }
        }

        vtr = 0;
        for(i=1;i<=n;i++)
        {
            vtr+=v[i];
            d = i-self[i]+vtr;
            printf("%d ",d);
        }
        printf("\n");
    }
    return 0;
}
