#include<stdio.h>
long long int a[1000000];
void quicksort(long long int first,long long int last)
{
    long long int pivot,j1,temp,i1;

     if(first<last)
        {
         pivot=first;
         i1=first;
         j1=last;
            while(i1<j1)
            {
                while(a[i1]<=a[pivot]&&i1<last)
                    i1++;
                while(a[j1]>a[pivot])
                    j1--;
                if(i1<j1)
                {
                    temp=a[i1];
                    a[i1]=a[j1];
                    a[j1]=temp;
                }
            }
         temp=a[pivot];
         a[pivot]=a[j1];
         a[j1]=temp;
         quicksort(first,j1-1);
         quicksort(j1+1,last);

        }
}
int main()
{
    long long int n,m,i,j,temp,p,q,r,s,sum=0;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]=a[i]*a[i];
    }
    quicksort(0,n-1);
    scanf("%lld",&m);
    for(i=0;i<m;i++)
    {
        scanf("%lld%lld%lld%lld",&p,&q,&r,&s);
        p=(p*p)+(q*q);
        q=(r*r)+(s*s);

        if(p>q)
        {
            r=p;
            p=q;
            q=r;
        }
        j=0;
        while(a[j]<q&&j<n)
        {
            if(a[j]>p)
            sum++;

            j++;
        }

    }
    printf("%lld",sum);
return 0;
}
