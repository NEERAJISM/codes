#include<iostream>
using namespace std;

int partition1(int *a,int p,int r)
{
    int i=p-1,x=a[r],t,j;

    for(j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }

    t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;

    return i+1;

}

void quicksort(int *a,int p, int r)
{
    if(p<r)
    {
        int q= partition1(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int  main()
{
    int a[100],n,i;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    quicksort(a,1,n);

    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";

return 0;
}
