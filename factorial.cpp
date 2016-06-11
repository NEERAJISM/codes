#include<iostream>
using namespace std;
int a[500];
int mul(int x,int asize)
{
    int c=0;
    for(int i=0;i<asize;i++)
    {
        int p = c+a[i]*x;
        c=p/10;
        a[i]=p%10;
    }

    while(c!=0)
    {
        a[asize]=c%10;
        c=c/10;
        asize++;
    }

    return asize;
}

void fact(int n)
{
    a[0]=1;
    int asize=1;

    for(int i=2;i<=n;i++)
        asize=mul(i,asize);

    for(int i=asize-1;i>=0;i--)
        cout<<a[i];

    cout<<endl;
}

int main()
{
    int t,n;
    cin>>t;

    while(t-->0)
    {
        cin>>n;
        fact(n);
    }
    return 0;
}
