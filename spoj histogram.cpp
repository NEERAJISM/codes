#include <bits/stdc++.h>
using namespace std;
long long int a[100005],b[10000007];
long long int tp,mx;
void create(long long int l,long long int r,long long int ind)
{
    if(l == r)
    {
        b[ind] = a[l];

        if(a[l] > mx)
            mx = a[l];
        return;
    }

    long long int mid = (l+r)/2;
    create(l,mid,2*ind+1);
    create(mid+1,r,2*ind+2);

    b[ind] = min(b[2*ind+1],b[2*ind+2]);
    tp = (r-l+1)*b[ind];

    if(tp > mx)
        mx = tp;
}
long long int query(long long int x,long long int y,long long int l,long long int r,long long int ind)
{
    if(l>y || r<x)
        return 0;
    else if(x<=l && y>=r)
        return b[ind]
    else
    {
        long long int mid =(l+r)/2;

    }
}

int main()
{
    long long int n,i,j,x,y;
    while(1)
    {
        mx = 0;
        scanf("%lld",&n);
        if(n == 0)
            break;

        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);

        create(0,n-1,0);

        for(i=0;i<n;i++)
        {
            while(a[i] == 0 && i<n)
                i++;

            if(i==n)
                break;

            x = i
                i++;
            while(a[i] != 0 && i<n)
                i++;

            y = i-1;
            tp = query(x,y,0,n-1,0);

            if(tp > mx)
                mx =tp;

            if(i == n)
                break;

            i--;
        }

        printf("%lld\n",mx);

        memset(b,0,sizeof(b));
    }
    return 0;
}
