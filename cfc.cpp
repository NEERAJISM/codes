#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000009

#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=s;i>=e;i--)

bool comp(pair<int,string> p1, pair<int,string> p2)
{
    if(p1.first >= p2.first)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ttt,i,j,k,m,n,d,flag,a,b;
    string s;

    vector< vector < pair < int,string> > > v(100005);

    cin>>n>>m;

    fp(i,0,n-1)
    {
        cin>>s>>j>>d;
        v[j].pb(mp(-d,s));
    }

    for(i=1;i<=m;i++)
    {
        flag = 0;

        sort(v[i].begin(),v[i].end(),comp);

        if(v[i][0].first != v[i][1].first && v[i][1].first != v[i][2].first)
            cout<<v[i][0].second<<" "<<v[i][1].second<<"\n";
        else
            cout<<"?\n";
    }
return 0;
}
