#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000009

#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=s;i>=e;i--)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ttt,i,j,k,m,n,d,flag,a,b;

    set<int> s;
    vector<int> v;

    cin>>n>>m;

    fp(i,0,n-1)
    {
        cin>>d;
        s.insert(d);
    }

    for(i=1;i<=1000000000;i++)
    {
        if(i>m || m<=0)
            break;

        if(s.find(i)  == s.end())
        {
            v.pb(i);
            m-=i;
        }
    }

    if(v.empty() == 0)
    {
        cout<<v.size()<<"\n";
        fp(i,0,v.size()-1)
            cout<<v[i]<<" ";
    }
    else
        cout<<"0\n";
return 0;
}
