#include <iostream>
#include <cstdio>
using namespace std;
int findgcd(int x,int y)
{
    int r,t;

    t=x;
    x=x>y?x:y;

    if(x==y)
        y=t;

    r=x%y;
    while(r!=0)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}

int main()
{
    int t,i,j,n,a[1001],gcd;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        gcd = findgcd(a[0],a[1]);

        for(i=2;i<n;i++)
        {
            gcd=  findgcd(gcd,a[i]);
        }

        for(i=0;i<n;i++)
            printf("%d ",a[i]/gcd);

        printf("\n");
    }
return 0;
}
