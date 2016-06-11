#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t,n,a[10005],count1;
    scanf("%d",&t);

    while(t--)
    {
        count1=0;
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

            if(count1== 0)
                count1++;
            else if(a[i-1]>=a[i])
            {
                count1++;
            }
            else
            {
                a[i]=a[i-1];
            }
        }

        printf("%d\n",count1);
    }
return 0;
}
