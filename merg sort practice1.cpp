#include <iostream>
#include <cstdio>
using namespace std;

void mergesort(int a[],int low,int mid,int high)
{
    int i,j,l1,l2,k;
    l1= mid -low+1;
    l2= high - mid;
    int b[l1+l2];
    i=low;
    j=mid+1;
    k=0;

    while(i<=mid &&j<=high)
    {
        if(a[i]<a[j])
        {
            b[k] =a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        b[k]= a[i];
        i++;
        k++;
    }

    while(j<=high)
    {
        b[k]= a[j];
        j++;
        k++;
    }

    for(i=0;i<k;i++,low++)
        a[low] = b[i];
}

void mergeit(int a[],int low,int high)
{
    if(low!=high)
    {
        int mid= (low+high)/2;
        mergeit(a,low,mid);
        mergeit(a,mid+1,high);
        mergesort(a,low,mid,high);
    }
}

int main()
{
    int n,a[100],i;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    mergeit(a,0,n-1);

    for(i=0;i<n;i++)
        printf("% d ",a[i]);
return 0;
}
