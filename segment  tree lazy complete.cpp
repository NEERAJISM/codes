#include <bits/stdc++.h>
using namespace std;
int lazy[1000];
void create_seg_tree(int a[],int b[],int l,int r,int ind)
{
    if(l==r)
    {
        b[ind] = a[l];
        return;
    }

    int mid = (l+r)/2;

    create_seg_tree(a,b,l,mid,2*ind+1);
    create_seg_tree(a,b,mid+1,r,2*ind+2);

    b[ind] = b[2*ind+1]+b[2*ind+2];
}

int query(int b[],int x,int y,int l, int r,int ind)
{
    if(lazy[ind] != 0)
    {
        b[ind] += (r-l+1)*lazy[ind];

        if(l != r)
        {
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    if(r<x || l>y)
        return 0;
    else if(x<=l && y>=r)
        return b[ind];
    else
    {
        int mid = (l+r)/2;
        return (query(b,x,y,l,mid,2*ind+1) +  query(b,x,y,mid+1,r,2*ind+2));
    }
}

void update(int b[],int x,int y,int val,int l,int r,int ind)
{
    if(lazy[ind] != 0)
    {
        b[ind] += (r-l+1)*lazy[ind];

        if(l!=r)
        {
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    if(l>y || r<x)
        return;
    else if((l>=x) && (r<=y))
    {
        b[ind] += (r-l+1)*val;

        if(l!=r)
        {
            lazy[2*ind+1] += val;
            lazy[2*ind+2] += val;
        }
    }
    else
    {
        int mid = (l+r)/2;

        update(b,x,y,val,l,mid,2*ind+1);
        update(b,x,y,val,mid+1,r,2*ind+2);

        b[ind] = b[2*ind+1] + b[2*ind+2];
    }
}

int main()
{
    int n,i,j,a[100],b[100],lazy[100],x,y,nn,diff,val;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    create_seg_tree(a,b,0,n-1,0);

    // RANGE query
    scanf("%d",&nn);
    for(i=0;i<nn;i++)
    {
        scanf("%d%d",&x,&y);
        cout<<query(b,x-1,y-1,0,n-1,0)<<"\n";
    }

    // range update
    scanf("%d",&nn);
    for(i=0;i<nn;i++)
    {
        scanf("%d%d%d",&x,&y,&val);
        update(b,x-1,y-1,val,0,n-1,0);
    }

    for(i=0;i<50;i++)
        cout<<b[i]<<" ";
    cout<<endl;

    //query
    scanf("%d",&nn);
    for(i=0;i<nn;i++)
    {
        scanf("%d%d",&x,&y);
        cout<<query(b,x-1,y-1,0,n-1,0)<<"\n";
    }

return 0;
}
