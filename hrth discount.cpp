#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long long int t,n,m,i,j,k,vali,a[1009],z;
    float val,price,one;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);

        for(i=0;i<n;i++)
        {
            val = 1000000000;
            for(j=1;j<=m;j++)
            {
                price  = 1000000000;
                for(k=1;k<=3;k++)
                {
                    scanf("%f",&one);
                    price = price - (price*one)/100;
                }

                if(val > price)
                {
                    val = price;
                    vali = j;
                }

            }
            a[i] = vali;
        }

        for(i=0;i<n;i++)
            printf("%lld ",a[i]);
        printf("\n");
    }
return 0;
}
