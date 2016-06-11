#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int lazy[10000000],b[10000000],a[100005];
long long int ttl;
void create_seg_tree(int l,int r,int ind)
{
    if(l==r)
    {
        b[ind] = a[l];
        return;
    }

    int mid = (l+r)/2;

    create_seg_tree(l,mid,2*ind+1);
    create_seg_tree(mid+1,r,2*ind+2);

    b[ind] = b[2*ind+1]+b[2*ind+2];
}

void update(int type,int x,int y,int v,int l,int r,int ind)
{
    if(lazy[ind]!=0)
    {
        b[ind] = (b[ind] + ((r-l+1)*lazy[ind]))%mod;

        if(l!=r)
        {
            lazy[2*ind+1] = (lazy[2*ind+1] + lazy[ind])%mod;
            lazy[2*ind+2] = (lazy[2*ind+2] + lazy[ind])%mod;
        }
        lazy[ind] = 0;
    }

    if(l>y || r<x)
        return;
    else if(x<=l && y>=r)
    {
        if(type == 1)
        {
            b[ind] = (b[ind]+(r-l+1)*v)%mod;

            if(l!=r)
            {
                lazy[2*ind+1] += v;
                lazy[2*ind+2] += v;
            }
        }
        else if(type == 2)
        {
            ttl = b[ind];
            ttl = (ttl*v)%mod;


            if(l!=r)
            {
                lazy[2*ind+1] += v;
                lazy[2*ind+2] += v;
            }
        }
        else
        {
            b[ind] += (r-l+1)*v;
        }

        return;
    }
    else
    {
        int mid = (l+r)/2;
        update(type,x,y,v,l,mid,2*ind+1);
        update(type,x,y,v,mid+1,r,2*ind+2);

        if(type == 1)
            b[ind] = (b[2*ind+1]+b[2*ind+2])%mod;
        else if(type == 2)

        else

    }
}

int query(int x,int y,int l,int r,int ind)
{
    if(lazy[ind] != 0)
    {
        b[ind] = (b[ind] + (r-l+1)*lazy[ind])%mod;

        if(l!=r)
        {
            lazy[2*ind+1] = (lazy[2*ind+1] +lazy[ind])%mod;
            lazy[2*ind+2] = (lazy[2*ind+2] +lazy[ind])%mod;
        }

        lazy[ind] = 0;
    }

    if((l>y) || (r<x))
        return 0;
    else if((x<=l) && (y>=r))
        return b[ind];
    else
    {
        int mid = (l+r)/2;
        return ((query(x,y,l,mid,2*ind+1) + query(x,y,mid+1,r,2*ind+2))%mod);
    }
}

int main()
{
    int n,i,j,ttt,c,type,x,y,v;
    scanf("%d%d",&n,&c);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    create_seg_tree(0,n-1,0);

    for(i=0;i<c;i++)
    {
        scanf("%d",&type);
        if(type == 1)
        {
            scanf("%d%d%d",&x,&y,&v);
            update(type,x-1,y-1,v,0,n-1,0);
        }
        else if(type == 2)
        {
            scanf("%d%d%d",&x,&y,&v);
            update(type,x-1,y-1,v,0,n-1,0);
        }
        else if(type == 3)
        {
            scanf("%d%d%d",&x,&y,&v);
            update(type,x-1,y-1,v,0,n-1,0);
        }
        else
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",query(x-1,y-1,0,n-1,0));
        }
    }
    return 0;
}

