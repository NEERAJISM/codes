#include<iostream>
using namespace std;
int main()
{
    int n,x,a[100007];

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];

    x=0;
    for(int i=0;i<n;i++)
    {
        x=x^a[i];
    }
    cout<<x;

    return 0;
}
