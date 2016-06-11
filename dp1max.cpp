#include<iostream>
using namespace std;
int a[10][2];
int main()
{
    int n,t,i,b,c;
    cin>>n;

    for(i=1;i<=n;i++)
        cin>>a[i][0];

    for(i=1;i<=n;i++)
    {
        b=0;
        c=0;
        t=i-2;
        if(t>=1)
        {
            b=a[t][1]+i*a[i][0];
        }
        else
            b=i*a[i][0];

        c=a[i-1][1];
        a[i][1]=b>c?b:c;
    }

    for(i=1;i<=n;i++)
        cout<<a[i][1]<<" ";

    return 0;
}
