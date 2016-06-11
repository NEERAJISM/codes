#include<stdio.h>
int a[10000000];
int main()
{
    int n=1,i,k,j,b[100],temp,count;

    for(i=1;i<=10000000;i++)
    {
        if(i%2==0)
            a[i]=2;
        else
            a[i]=1;
    }
    for(i=3;i<=10000000;i+=2)
    {
        if(a[i]==1)
        {
            for(j=i;j<=10000000;j+=i)
                a[j]=i;
        }
    }

    while(scanf("%d",&n)!=-1)
    {
        k=0;
        b[k]=a[n];
        n=n/a[n];
        k++;

        while(a[n]>1)
        {
            i=k-1;
            while(b[i]<a[n]&&i>=0)
            {
                b[i+1]=b[i];
                i--;
            }
            i++;
            b[i]=a[n];
            k++;
            n=n/a[n];
        }
    }
return 0;
}

