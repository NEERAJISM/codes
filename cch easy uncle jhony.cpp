#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,a[102],init,i,j,k,finalp,val;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);

        scanf("%d",&k);
        val = a[k];

        sort(a+1,a+n+1);

        if(val<a[k])
        {
            for(i=k-1;i>0;i--)
                if(a[i]==val)
                    break;
        }
        else
        {
            for(i=k;i<=n;i++)
                if(a[i]==val)
                    break;
        }
        printf("%d\n",i);
    }
return 0;
}
