#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int t,n,d,a[100005],i,j,current,county,flag;
    long long int sum;

    scanf("%d",&t);
    while(t--)
    {
        sum =0;
        scanf("%d%d",&n,&d);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        sort(a,a+n);

        for(i=n-1;i>=0;i--)
        {
            //cout<<i<<"**"<<a[i]<<endl;
            current = a[i];
            i--;

            if(i<0)
                break;

            //cout<<i<<" ** "<<a[i]<<endl;

            if(current - a[i] < d)
            {
                //cout<<current<<" "<<a[i]<<endl;
                sum+=current+a[i];
            }
            else
                i++;
        }
        printf("%lld\n",sum);
    }
return 0;
}
