#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,i,j,a[30],b[30],count1;

    scanf("%d",&t);

    while(t--)
    {
        count1=0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=0;i<n;i++)
            scanf("%d",&b[i]);

        sort(a,a+n);
        sort(b,b+n);

        i=0;
        j=0;

        while(j<n)
        {
            if(a[i]<=b[j])
            {
                count1++;
                i++;
            }
            j++;
        }
        printf("%d\n",count1);
    }
return 0;
}
