#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long long int k,a[100000],t,n,left,open,i,j,packets,req,count1;
    scanf("%lld",&t);
    while(t--)
    {
        packets = 0;
        left = 0;
        count1=0;
        scanf("%lld%lld",&n,&k);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        {
            req= a[i]-left;
            packets = req/k;
            if(req>packets*k)
                packets++;
            left = packets*k -req;
            if(left>0)
                left--;
            count1 = count1 + packets;
        }
        printf("%lld\n",count1);
    }
return 0;
}
