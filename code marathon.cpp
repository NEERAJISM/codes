#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
char s[100005];
int main()
{
    long long int i,j,n,m,ttt,ind =(long long int)'a',k,rslt,sm,qty,vl,l,n1;

    scanf("%lld",&ttt);
    while(ttt--)
    {
        vector<long long int> v(26,0);
        vector<long long int> d;
        vector<long long int> tl(26,0);

        scanf("%s",s);
        scanf("%lld",&k);
        n = strlen(s);

        for(i=0;i<n;i++)
            v[(long long int)s[i] -ind]++;

        for(i=0;i<26;i++)
            if(v[i] > 0)
                d.push_back(v[i]);

        sort(d.begin(),d.end(),greater<int>());

        n1 = n;
        n = d.size();
        i=1;
        rslt = 0;
        qty = 0;
        sm = 0;

        if(n1>k)
        {
            sm = d[0];
            qty = 1;
            tl[0] = 0;
            while(i<n)
            {
                if(d[i] < sm)
                    tl[i] = tl[i-1]+(sm - d[i])*qty;

                qty++;
                i++;
            }

            i = 0;
            while(1)
            {
                if(i == n || k<tl[i])
                    break;
                i++;
            }

            //cout<<i<<endl;

            if(i==n)
            {
                sm  = d[n-1];
                k-= tl[n-1];
                //cout<<k<<endl;
                l = k/n;
                sm-=l;
                //cout<<sm<<endl;
                k = k%n;

                rslt= (rslt+(k*((sm-1)*(sm-1))%mod)%mod)%mod;
                rslt= (rslt + (abs(n-k)*((sm)*(sm))%mod)%mod)%mod;
            }
            else
            {
                sm = d[i-1];
                k-=tl[i-1];
                l = i;

                while(i<n)
                {
                    rslt=(rslt+(d[i]*d[i])%mod)%mod;
                    i++;
                }

                i = l;
                l = k/i;
                sm-=l;
                k = k%i;
                rslt= (rslt+(k*((sm-1)*(sm-1))%mod)%mod)%mod;
                //cout<<rslt<<endl;
                rslt = (rslt+(abs(i-k)*((sm)*(sm))%mod)%mod)%mod;
                //cout<<rslt<<endl;
            }
        }
        else
            rslt = 0;

        printf("%lld\n",rslt%mod);
    }
    return 0;
}
