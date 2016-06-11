#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int m,n,a[10001],girls[1001],i,j,temp,qual[1001],z=0;
    scanf("%d",&m);

    for(i=0;i<m;i++)
        scanf("%d",&qual[i]);

    sort(qual,qual+m);

    scanf("%d",&n);
    j=0;

    for(i=0;i<n;i++)
    {
        int size1=0;
        j=0;
        while(scanf("%d",&a[j]))
            size1++;

        sort(a,a+size1);
        j=0;
        for(i=0;i<m;i++)
        {
            if()
        }

    }

return 0;
}
