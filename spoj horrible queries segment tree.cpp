#include <bits/stdc++.h>
using namespace std;
long long int lazy[10000000],b[10000000];

void update(long long int x,long long int y,long long int v,long long int l,long long int r,long long int ind)
{
    if(lazy[ind]!=0)
    {
        b[ind] += ((r-l+1)*lazy[ind]);

        if(l!=r)
        {
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if(l>y || r<x)
        return;
    else if(x<=l && y>=r)
    {
        b[ind] += (r-l+1)*v;

        if(l!=r)
        {
            lazy[2*ind+1] += v;
            lazy[2*ind+2] += v;
        }
        return;
    }
    else
    {
        long long int mid = (l+r)/2;
        update(x,y,v,l,mid,2*ind+1);
        update(x,y,v,mid+1,r,2*ind+2);
        b[ind] = b[2*ind+1]+b[2*ind+2];
    }
}

long long int query(long long int x,long long int y,long long int l,long long int r,long long int ind)
{
    if(lazy[ind] != 0)
    {
        b[ind] += ((r-l+1)*lazy[ind]);

        if(l!=r)
        {
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    if((l>y) || (r<x))
        return 0;
    else if((x<=l) && (y>=r))
        return b[ind];
    else
    {
        long long int mid = (l+r)/2;
        return (query(x,y,l,mid,2*ind+1) + query(x,y,mid+1,r,2*ind+2));
    }
}

int main()
{
    long long int n,i,j,ttt,c,type,x,y,v;
    scanf("%lld",&ttt);

    while(ttt--)
    {
        scanf("%lld%lld",&n,&c);
        for(i=0;i<c;i++)
        {
            scanf("%lld",&type);
            if(type == 0)
            {
                scanf("%lld%lld%lld",&x,&y,&v);
                update(x-1,y-1,v,0,n-1,0);
            }
            else
            {
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",query(x-1,y-1,0,n-1,0));
            }
        }
        memset(b,0,sizeof(b));
        memset(lazy,0,sizeof(lazy));
    }
    return 0;
}
