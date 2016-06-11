#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t,n,d,a[100005],i,j,current,county,flag,temp,max1,x,y;
    long long int sum;
    scanf("%d",&t);
    while(t--)
    {
        max1=0;

        for(i=0;i<=100001;i++)
            a[i] = 0;

        sum =0;
        scanf("%d%d",&n,&d);

        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            a[temp] = 1;

            if(temp > max1)
                max1=temp;
        }

        i=max1;

        while(i>0)
        {
            while(a[i]!=1)
            {
                if(i<=0)
                    break;
                 i--;
            }

            if(i <= 0)
                break;

            x=i;
            i--;

            while(a[i]!=1)
            {
                if(i<=0)
                    break;
                i--;
            }

            if(i<=0)
                break;

            if(x-i < d)
            {
                sum+= x+i;
                i--;
            }
        }
        printf("%lld\n",sum);
    }
return 0;
}
