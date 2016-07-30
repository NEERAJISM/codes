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

    int ttt,i,j,x,y,k,m,n,q,d;

    string a,b;
    cin>>a>>b;

    m = a.length();
    n = b.length();

    int mi[100][100];

    for(i=m;i>=0;i--)
    {
        for(j=n;j>=0;j--)
        {
            if(i==m || j == n)
            {
                mi[i][j] = 0;
                continue;
            }

            if(a[i] == b[j])
                mi[i][j] = 1+ mi[i+1][j+1];
            else
                mi[i][j] = max(mi[i+1][j],mi[i][j+1]);
        }
    }

    cout<<mi[0][0];
    return 0;
}
