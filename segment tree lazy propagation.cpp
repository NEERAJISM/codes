#include <iostream>
#include <cstdio>
using namespace std;
int a[100],b[201],lazy[202];

void buildseg(int pos,int low,int high)
{
    if(low==high)
    {
        b[pos] = a[low];
        return;
    }

    int mid = (low+high)/2;
    buildseg(2*pos+1,low,mid);
    buildseg(2*pos+2,mid+1,high);

    b[pos] = b[pos*2+1]+b[pos*2+2];
}

void rangeupdate(int pos,int low,int high,int x,int y,int val)
{
    if(lazy[pos]!=0)
    {


        if(low!=high)
        {
            lazy[2*pos+1] = lazy[pos];
            lazy[2*pos+2] = lazy[pos];
        }
        lazy[pos]=0;
    }

    if(low>high || low>y ||high <x)
        return;

    if(x<=low && y>=high)
    {
        b[pos] = (low-high+1)*val;

        cout<<endl<<pos<<" "<<b[pos]<<" ";
        b[pos] = (low-high+1)*lazy[pos];
        cout<<b[pos]<<" "<<lazy[pos]<<endl;

        if(low!=high)
        {
            lazy[2*pos+1]+=val;
            lazy[2*pos+2]+=val;
        }
        return;
    }

    int mid =(low+high)/2;
    rangeupdate(2*pos+1,low,mid,x,y,val);
    rangeupdate(2*pos+2,mid+1,high,x,y,val);

    b[pos] = b[2*pos+1] +b[2*pos+2];
}

int main()
{
    int n,i,x,y,val;
    cin>>n;

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    buildseg(0,0,n-1);
    for(i=0;i<2*n+10;i++)
        cout<<b[i]<<" ";

    scanf("%d%d%d",&x,&y,&val);

    cout<<endl;
    //for(i=0;i<2*n;i++)
    rangeupdate(0,0,n-1,x,y,val);

    for(i=0;i<2*n+10;i++)
        cout<<b[i]<<" ";

return 0;
}
/*
6
5 1 2 3 4 8
*/
