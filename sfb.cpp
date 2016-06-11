#include <bits/stdc++.h>
using namespace std;
long long int d[100004];
long long int ind[100004];
int main()
{
   long long int i,j,ttt,k,n,rslt = 0,r,tmp,x,y,flag;
   scanf("%lld%lld",&k,&n);

   for(i=0;i<k;i++)
   {
        scanf("%lld",&r);
        ind[r] = i+1;
        d[r] = -1;
   }

   tmp = -3;
   for(i=100000;i>=0;i--)
   {
        if(d[i] == -1)
            tmp = i;
        else
            d[i] = tmp;
   }

    for(i=0;i<=100000;i++)
    {
        if(d[i] == -1 || d[i] == -3)
            break;
        else
            d[i] = -2;
    }

   for(i=0;i<n;i++)
   {
        scanf("%lld%lld",&x,&y);
        float x1 = (pow(x*x + y*y),0.5);
        x =(long long int)x1;

        float x2 = (float)x;

        flag = 0;
        if(x1 > x2)
            flag = 1;

        if(d[x]==-1)
        {
            rslt+=ind[x];

            if(flag == 1)
                rslt-=1;
        }
        else if(d[x]==-2)
        {
            rslt+= k;
        }
        else if(d[x]==-3)
        {
            rslt+= 0;
        }
        else if(d[x] > 0)
            rslt+=ind[d[x]];
   }
   printf("%lld\n",rslt);
}
