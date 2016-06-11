#include <iostream>
#include <cstdio>

#define mod 1000000007
using namespace std;
int main()
{
    int n,q,i,j,x,y,v,type;
    long long int a[100005];
    scanf("%d%d",&n,&q);

    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);

    for(j=1;j<=q;j++)
    {
        scanf("%d",&type);

        if(type == 1)
        {
            scanf("%d%d%d",&x,&y,&v);

            for (i = x; i <= y; i++)
            {
                a[i]+=v;
                a[i] = a[i]%mod;
            }
        }
        else if(type ==2)
        {
            scanf("%d%d%d",&x,&y,&v);
            for (i = x; i <= y; i++)
                a[i] = (a[i]*v)%mod;
        }
        else if(type == 3)
        {
            scanf("%d%d%d",&x,&y,&v);
            for (i = x; i <= y; i++)
                a[i] = v;
        }
        else
        {
            scanf("%d%d",&x,&y);
            long long int sum=0;
            for(i=x;i<=y;i++)
            {
                sum = (sum+a[i])%mod;
            }

            printf("%lld\n",sum);
        }
    }
return 0;
}

