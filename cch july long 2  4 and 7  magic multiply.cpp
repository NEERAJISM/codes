#include <iostream>
#include <cstdio>
long long int a[100000],temp;
using namespace std;
int main()
{
    int n,t,i,min1,flag,numzero;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);

    for(i=0;i<n;i++)
    {
        temp =a[i];

        while(temp%5==0)
        {
            while(temp%10==0)
            {
                temp=temp/10;
            }

            if(temp%10==5)
            {
                temp = temp*4;
                a[i]=a[i]*4;
            }
        }
    }

    for(i=0;i<n;i++)
        printf("%lld\n",a[i]);

return 0;
}
