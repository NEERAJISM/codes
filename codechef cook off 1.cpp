#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,m,x,y,temp,i,a[11],product,b[11],county,initial;
    scanf("%d",&t);

    while(t--)
    {
        county =0;
        scanf("%d%d%d",&m,&x,&y);
        product =x*y;

        for(i=0;i<m;i++)
            scanf("%d",&a[i]);

        sort(a,a+m);

        for(i=0;i<m;i++)
        {
            temp =a[i];
            a[i] = temp - product;
            b[i] = temp + product;
        }



        initial =1;
        for(i=0;i<m;i++)
        {
            if(a[i]>initial)
            {
                county += a[i]-initial;
            }

            initial = b[i]+1;
        }

        if(initial<=100)
            county+=100-initial+1;

        printf("%d\n",county);
    }
return 0;
}
