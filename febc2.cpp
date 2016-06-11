#include<iostream>

int b[100000];
using namespace std;
int main()
{
    int n,t,i,d,max,v,a[100000];
    cin>>t;
    while(t-->0)
    {
        cin>>n;
        max=0;

        for(i=0;i<n;i++)
        {
            cin>>a[i];
            max=max>a[i]?max:a[i];
            b[a[i]]++;
        }

        v=max;
        max=0;

        for(i=0;i<=v;i++)
        {
            if(b[i]!=0)
            {
                max=max>b[i]?max:b[i];
                b[i]=0;
            }
        }
        cout<<n-max<<endl;
    }
    return 0;
}
