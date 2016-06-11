#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a,sum=0,total;

    cin>>n;

    total = n*(n+1)/2;

    for(int i = 0;i<n ;i++)
    {
        cin>>a;
        sum+=a;
    }

    cout<<total-sum;


    return 0;

}
