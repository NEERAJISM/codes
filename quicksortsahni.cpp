#include<bits/stdc++.h>
using namespace std;
int a[100],n;

int partition1(int* a,int m, int n)
{
    int i=m,t,j=n,pivot=m;

    while(i<j)
    {
        while(a[i]<a[pivot]&&i<n)
            i++;
        while(a[j]>a[pivot])
            j--;

        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }

    a[m]=a[j];
    a[j]=a[pivot];

    return j;
}

void quicksort(int *a,int p,int q)
{
    if(p<q)
    {
        int j=partition1(a,p,q);
        quicksort(a,p,j-1);
        quicksort(a,j+1,q);
    }
}

int main()
{
   cin>>n;

   for(int i=0;i<n;i++)
        cin>>a[i];

    quicksort(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

return 0;
}
