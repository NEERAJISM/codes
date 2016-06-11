#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define ll long long

#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=e;i>=s;i--)

#define vi vector<int>
#define vvi vector<vector<int> >

// end of template

long long int a[10000007];

int main()
{
    long long int i,j,k,n,ttt,ext,q,l,r,len,res,rn,ln;

    a[0] = 0;

    for(i=1;i<=100000;i++)
        a[i] = (a[i-1]^i);

    scanf("%lld",&q);

    for(i=0;i<q;i++)
    {
        scanf("%lld%lld",&l,&r);

        if(r<=100000)
        {
            len = (r-l+1);
            res = 0;

            for(j = l+1;j<=r;j+=2)
                res = (res^j);

            if(j==(r+1))
                res = (res^a[r]);
            printf("%lld\n",res);
        }
        else
        {
            l+=1;

            if((r-ln)%2 != 0)
            {
                rn = r;
                r -=1;
            }
            res = 0;

            if(l%2 == 1)
            {
                if(l%4 == 1)
                {
                    if((r-l+1)%4 != 0)
                        res = 2;

                    if((r-l+1)%2 != 0)
                        res  = res^r;
                }
                else
                {
                    res = l;
                    l = l+1;

                    if((r-l+1)%4 != 0)
                        res = res^2;

                    if((r-l+1)%2 != 0)
                        res  = res^r;
                }
            }
            else
            {
                if(l%4 == 0)
                {
                    if((r-l+1)%4 != 0)
                        res = 2;

                    if((r-l+1)%2 != 0)
                        res  = res^r;
                }
                else
                {
                    res = l;
                    l = l+1;

                    if((r-l+1)%4 != 0)
                        res = 2;

                    if((r-l+1)%2 != 0)
                        res  = res^r;
                }
            }

            if((rn-l)%2 != 0)
            {
                r = rn;
            if(r%4 == 0)
                res = (res^r);
            else if(r%4 == 1)
            {
                res = (res^1);
            }
            else if(r%4 == 2)
            {
                res = (res^(r+1));
            }
            else if(r%4 == 3)
            {
                res = (res^0);
            }
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}

