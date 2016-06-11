#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int x[10000000];
int main()
{
    int n;

    cin>>n;

    for(int i=2;i<=sqrt(n);i++)
    {
        cout<<"/*11/*"<<endl;
        if(x[i]==0)
        {
            cout<<"/*22/*"<<endl;

            cout<<x[i]<<" ";

            int j=2;
            for(int j=j*i;i*j<=n;j++)
                x[j]=1;
        }
    }
    return 0;
}
