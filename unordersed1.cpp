#include<bits/stdc++.h>
using namespace std;
int sum,d1,d2,lsum,rsum,msum;

int maxcrossarray(int* a,int i,int j,int k,int* low,int *high)
{
    int i1,j1,sum1=0,lsum1=INT_MIN,rsum1=INT_MIN;

    for(i1=j;i1>=i;i1--)
    {
        sum1=sum1+a[i1];

        if(sum1>lsum1)
        {
            *low=i1;
            lsum1=sum1;
        }
    }
    sum1=0;

    for(j1=j+1;j1<=k;j1++)
    {
        sum1=sum1+a[j1];

        if(sum1>rsum1)
        {
            *high=j1;
            rsum1=sum1;
        }
    }
    return rsum1+lsum1;

}

int maxsubarray(int *a,int x,int y,int* low1,int*high1)
{
    int low2,high2,low3,high3;
    if(x==y)
    {
        *low1=x;
        *high1=x;
        return a[x];
    }
    else
    {
        int mid=(x+y)/2;
       lsum= maxsubarray(a,x,mid,low1,high1);
       rsum= maxsubarray(a,mid+1,y,&low2,&high2);
       msum= maxcrossarray(a,x,mid,y,&low3,&high3);

    if(lsum>rsum&&lsum>msum)
        return lsum;

    else if(rsum>lsum&&rsum>msum)
    {
        *low1=low2;
        *high1=high2;
     return rsum;
    }
    else
    {
        *low1=low3;
        *high1=high3;

        return msum;
    }
    }
}

int main()
{
    int n,a[100],i,j,low,high;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<maxsubarray(a,0,n-1,&low,&high)<<" "<<low<<" "<<high;

    return 0;
}
