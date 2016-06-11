#include <bits/stdc++.h>
using namespace std;
int a[30004],b[1000006];
void create_seg_tree(int l,int r,int ind,int v)
{
    if(l==r)
    {
        if(a[l] > v)
            b[ind] = 1;
        else
            b[ind] = 0;
        return;
    }

    int mid = (l+r)/2;
    create_seg_tree(l,mid,2*ind+1,v);
    create_seg_tree(mid+1,r,2*ind+2,v);
    b[ind] = b[2*ind+1] + b[2*ind+2];
}

int query(int x,int y,int v,int l,int r,int ind)
{
    if(l>y || r<x)
        return 0;

    if(l==r && (l>=x && l<=y))
    {
        if(a[l] > v)
            return 1;
        else
            return 0;
    }
    else
    {
        int mid = (l+r)/2;
        return (query(x,y,v,l,mid,2*ind+1) + query(x,y,v,mid+1,r,2*ind+2));
    }
}

int main()
{
    int n,i,j,q,x,y,v;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&q);
    create_seg_tree(0,n-1,0,0);
    for(i=0;i<q;i++)
    {
        scanf("%d%d%d",&x,&y,&v);
        printf("%d\n",query(x-1,y-1,v,0,n-1,0));
    }
    return 0;
}
