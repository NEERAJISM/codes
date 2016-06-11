#include<iostream>
#include<cmath>
using namespace std;
int a[100000],i,n,j;
int main()
{
    cin>>n;

    for(i=3;i<sqrt(n);i+=2)
    {
        if(a[i]==0)
        {
            for(j=2;j*i<n;j++)
                    a[j*i]=1;

        }
    }

    cout<<"2 ";

    for(i=3;i<n;i+=2)
    {
        if(a[i]==0)
            cout<<i<<" ";
    }
    return 0;
}
