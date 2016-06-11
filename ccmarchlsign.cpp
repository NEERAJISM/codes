#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    unsigned long long int t,s,c,k,result;
    cin>>t;

    while(t--)
    {
        cin>>s>>c>>k;
        if(c>=s-k+1)
            s++;

        result=3+2*(pow(2,s-k)-1);

        if(k==1&&c>s)
            result=pow(2,c);

        cout<<result<<endl;
    }
    return 0;
}
