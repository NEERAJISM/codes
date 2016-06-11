//merge sort
#include<bits/stdc++.h>
using namespace std;
int a[1000000];

void mergesort(int *a,int x1,int m1,int y1)
{
    int k=0,a1[100];
    int p =x1,q=m1+1;
    while(p<=m1&&q<=y1)
    {
        if(a[p]<a[q])
        {
            a1[k]=a[p];
            p++;
        }
        else
        {
            a1[k]=a[q];
            q++;
        }
        k++;
    }

        if(q<y1)
        {
            while(q<=y1)
            {
                a1[k]=a[q];
                k++;
                q++;
            }
        }
        else
        while(p<=m1)
        {
            a1[k]=a[p];
            k++;
            p++;
        }

        for(int i=x1,j=0;i<=y1;j++,i++)
            a[i]=a1[j];

}

void merge(int *a,int x,int y)
{
    if(x<y)
    {
        int m=(x+y)/2;
        merge(a,x,m);
        merge(a,m+1,y);
        mergesort(a,x,m,y);
    }

}

int main()
{
    int t,n,i;

    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];

    merge(a,0,n-1);

    for(i=0;i<n;i++)
        cout<<a[i]<<endl;

    return 0;
}
