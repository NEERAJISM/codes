#include <bits/stdc++.h>
using namespace std;
int a[50004],b[5000000];

void create(int l,int r,int ind)
{
    if(l==r)
    {
        b[ind] = a[l];
        return;
    }

    int mid = (l+r)/2;
    create(l,mid,2*ind+1);
    create(mid+1,r,2*ind+2);
    b[ind] = b[2*ind+1] + b[2*ind+2];
}

int main()
{
    int n,i,q;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    create(0,n-1,0);

    scanf("%d",&q);

    for(i=0;i<q;i++)
    {

    }

}
