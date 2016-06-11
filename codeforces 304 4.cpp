#include <bits/stdc++.h>
using namespace std;
long long int i,t,rounds = 0,a,b;

void findprimefactors(int n)
{
    int i;
    while (n%2 == 0)
    {
        rounds++;
        n = n/2;
    }
    for(i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            rounds++;
            n = n/i;
        }
    }
    if (n > 2)
        rounds++;
}

int main()
{
    cin>>t;
    while(t--)
    {
        rounds = 0;
        cin>>a>>b;

        for(i=a ; i>b ; i--)
        {
            findprimefactors(i);
        }

        cout<<rounds<<endl;

    }
    return 0;
}
