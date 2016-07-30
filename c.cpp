#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ttt,i,flag,j,k,m,n,tmp,bas,cnt,po10[6],val,unt;
    string s;
    cin>>ttt;

    po10[0] = 1;
    for(i=1;i<=4;i++)
        po10[i] = 10*po10[i-1];

    while(ttt--)
    {
        cin>>s;

        n = s.length();
        bas = (int)'0';
        flag = 0;
        tmp = 0;
        cnt = 0;
        unt = 1;

        for(i=n-1;i>=0;i--)
        {
            if(s[i] == '.')
            {
                flag = 1;
                break;
            }

            tmp+=((s[i]-bas)*unt);
            unt*=10;
            cnt+=1;
        }

        if(flag == 0)
            cout<<"1\n";
        else
        {
            val = __gcd(tmp,po10[cnt]);
            //cout<<tmp<<" "<<val<<"*\n";
            cout<<po10[cnt]/val<<"\n";
        }
    }
return 0;
}
