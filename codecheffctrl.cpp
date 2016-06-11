#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,n,z,t2,i;

    cin>>t;
    while(t--)
    {
        cin>>n;
        z=0;
        i=1;

        t2 = n/pow(5,i);

        while(t2 != 0)
        {
            z=z+t2;
            i++;
            t2 = n/pow(5,i);
        }

        cout<<z<<endl;
    }
    return 0;
}
