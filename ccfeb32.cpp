#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long long int n,t,s,t1,t2;
    cin>>t;
    while(t-->0)
    {
        cin>>n>>s;
        t1=(n*(n+1))/2;
        if(s==t1)
            cout<<"0"<<endl;
        else
        {
            s=t1-s;
            t2=nwtn((float)s/2,s);
            cout<<t2<<endl;
        }
    }
    return 0;
}
