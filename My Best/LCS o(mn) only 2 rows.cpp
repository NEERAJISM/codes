#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ttt,i,j,x,y,k,m,n,q,d,ii;

    string a,b;
    cin>>a>>b;

    m = a.length();
    n = b.length();

    int mi[2][100];

    for(i=m;i>=0;i--)
    {
        ii = i&1;

        for(j=n;j>=0;j--)
        {
            if(i==m || j == n)
            {
                mi[ii][j] = 0;
                continue;
            }

            if(a[i] == b[j])
                mi[ii][j] = 1+ mi[1-ii][j+1];
            else
                mi[ii][j] = max(mi[1-ii][j],mi[ii][j+1]);
        }
    }

    cout<<mi[0][0];
    return 0;
}

