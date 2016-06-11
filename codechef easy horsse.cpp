#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,a[5001],i,min1;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        sort(a,a+n);

        min1 = 1000000001;

        for(i=1;i<n;i++)
            if(a[i]-a[i-1]<min1)
                min1 = a[i]-a[i-1];

        printf("%d\n",min1);
    }
return 0;
}
