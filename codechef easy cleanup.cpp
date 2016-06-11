#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int t,n,m,c[1000],a[1000],c1,a1,i,temp,flag;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);

        vector<int> v(n+1,0);

        for(i=0;i<m;i++)
        {
            scanf("%d",&temp);
            v[temp] = 1;
        }
        flag=0;
        c1=0;
        a1=0;
        for(i=1;i<=n;i++)
        {
            if(v[i]==0)
            {
                if(flag==0)
                {
                    c[c1] = i;
                    c1++;
                    flag++;
                }
                else
                {
                    a[a1] = i;
                    a1++;
                    flag--;
                }
            }
        }
        for(i=0;i<c1;i++)
            printf("%d ",c[i]);

        printf("\n");

        for(i=0;i<a1;i++)
            printf("%d ",a[i]);

        printf("\n");
    }
return 0;
}


