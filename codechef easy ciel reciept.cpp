#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t,a[12],p,count1,mul,i;
    a[0]=1;

    for(i=1;i<12;i++)
        a[i] = 2*a[i-1];

    scanf("%d",&t);
    while(t--)
    {
        count1 = 0;
        scanf("%d",&p);
        i=11;
        while(p>0)
        {
            if(p>=a[i])
            {
                count1 = count1 + p/a[i];
                p=p%a[i];
            }
             i--;
        }

        printf("%d\n",count1);
    }
return 0;
}
