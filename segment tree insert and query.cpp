#include <bits/stdc++.h>
using namespace std;
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

int query(int b[],int l,int r,int x, int y,int ind)
{
    if(x>=l && y<=r)
        return b[ind];
    else if(y<l || x > r)
        return 0;
    else
    {
        int mid = (x+y)/2;
        return (query(b,l,r,x,mid,2*ind+1)+ query(b,l,r,mid+1,y,2*ind+2));
    }
}

void update(int b[],int x,int y,int l,int r,int ind)
{
    if((l==x)&& (r==x))
    {
        b[ind] += y;
        return;
    }
    else if((l<=x) && (r>=x))
    {
        b[ind] += y;
        int mid = (l+r)/2;
        update(b,x,y,l,mid,2*ind+1);
        update(b,x,y,mid+1,r,2*ind+2);
    }
}

int main()
{
    int n,i,j,a[1000],b[10000],x,y,nn,diff;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    create_seg_tree(a,b,0,n-1,0);
    //query
    scanf("%d",&nn);
    for(i=0;i<nn;i++)
    {
        scanf("%d%d",&x,&y);
        cout<<query(b,x-1,y-1,0,n-1,0)<<"\n";
    }

    //update
    scanf("%d",&nn);
    for(i=0;i<nn;i++)
    {
        scanf("%d%d",&x,&y);
        diff = y-a[x-1];
        update(b,x-1,diff,0,n-1,0);
    }


    for(i=0;i<50;i++)
        cout<<b[i]<<" ";

    cout<<endl;

    scanf("%d",&nn);
    for(i=0;i<nn;i++)
    {
        scanf("%d%d",&x,&y);
        cout<<query(b,x-1,y-1,0,n-1,0)<<"\n";
    }
return 0;
}
