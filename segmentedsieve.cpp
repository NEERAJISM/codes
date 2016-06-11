#include<iostream>
#include<cmath>
using namespace std;
int p[10000000],a[10000000];
int main()
{
    int n,m,i,j,t,k=0,n1,t1;

    for(i=4;i<=100000;i+=2)
        p[i]=1;

    n1=sqrt(1000000000);
    for(i=3;i<=sqrt(n1);i+=2)
    {
        if(p[i]==0)
        {
            for(j=2;i*j<=n1;j++)
                p[i*j]=1;
        }
    }

    cin>>t;

    while(t--)
    {
        cin>>m>>n;
    for(i=2;i<=sqrt(n);i++)
    {
        if(p[i]==0)
        {
            t=i-m%i;
            if(t==i)
                a[0]=1;

            for(j=t;j<=n-m+1;j=j+i)
                if(j+m!=i)
                    a[j]=1;
        }
    }

        for(int i1=0;i1<=n-m;i1++)
        {
            if(a[i1]==0)
                cout<<i1+m<<" ";
        }

    }

    return 0;
}
