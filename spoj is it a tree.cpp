#include <iostream>
#include <cstdio>
#include <vector>
using namespace  std;
int main()
{
    int n,m,i,j,flag1,flag2,x,y;

    scanf("%d%d",&n,&m);
    vector<int> v(n+1,0);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);

        if(v[x]==0)
            v[x]=1;

        if(v[y]==0)
            v[y] =1;
    }

    flag2=1;
    for(i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            flag2=0;
            break;
        }
    }

    if(flag2==1)
    {
        if(m == n-1)
            flag1=1;

        if(flag1==1 && flag2 ==1)
            printf("YES");
        else
            printf("NO");
    }
    else
        printf("NO");

return 0;
}
