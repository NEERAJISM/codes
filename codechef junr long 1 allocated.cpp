#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long int t,n,allot,prev,curr,d,i;
    scanf("%lld",&t);

    while(t--)
    {
        allot = 0;
        scanf("%lld",&n);

        prev = 0;
        for(i=0 ; i<n ; i++)
        {
            scanf("%lld",&curr);

            if(curr > prev)
                allot = allot+ curr - prev;

            prev = curr;
        }
        printf("%lld\n",allot);
    }
return 0;
}
