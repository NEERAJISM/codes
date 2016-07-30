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

    int ttt,i,j,k,m,n,d,flag,x,y,z;


    cin>>ttt;
    while(ttt--)
    {
        set<int> p;
        flag = 0;
        cin>>n>>x>>y>>z>>d;

        p.insert(1);
        p.insert(x);
        p.insert(y);
        p.insert(z);

        if(d%2 == 0)
            p.insert(2);

        while (d%2 == 0)
            d = d/2;

        for (int i = 3; i <= sqrt(d); i = i+2)
        {
            if(d%i == 0)
                p.insert(i);

            while (d%i == 0)
                d = d/i;
        }

        if (d > 2)
            p.insert(d);

        for(i=1;i<n;i++)
        {
            cin>>d;

            if(flag == 0)
            {
                if(d%2 == 0)
                {
                    if(p.insert(2).second)
                    {
                        //cout<<2<<"*\n";
                        flag = 1;
                    }
                }

                if(flag == 0)
                    while (d%2 == 0)
                        d = d/2;

                if(flag == 0)
                {
                    for (int i = 3; i <= sqrt(d); i = i+2)
                {
                    if(d%i == 0)
                        if(p.insert(i).second)
                        {
                            //cout<<i<<"*\n";
                            flag = 1;
                            break;
                        }

                    while (d%i == 0)
                        d = d/i;
                }
                }

                if (flag == 0 && d > 2)
                {
                    if(p.insert(d).second)
                    {
                        //cout<<d<<"*\n";
                        flag = 1;
                    }
                }
            }
        }

        if(flag == 0)
            cout<<"She can\n";
        else
            cout<<"She can't\n";

        p.clear();
    }

return 0;
}

