#include <bits/stdc++.h>
using namespace std;

#define mod 1000000009
#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=e;i>=s;i--)

#define s(n) scanf("%d",&n);
#define p(n) printf("%d",n);
#define pn(n) printf("%d\n",n);

#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long
char c[500005];
int main()
{
    long long int ttt,i,i1,j,n,rslt,nl,tmp,k,in,fin,flag,l,ind;
    vector<char> v;
    s(ttt)

    while(ttt--)
    {
        scanf("%s",c);
        n = strlen(c);
        rslt = n;

        for(ind = 1;ind<=n;ind++)
        {
            if((ind*(2) > n))
                break;

            for(i1=2;i1<=n;i1++)
            {
                if(ind%i1 == 0)
                    continue;

                tmp = ind;
                while(tmp<=n)
                {
                    v.push_back(c[tmp-1]);
                    tmp*=i1;
                }

                nl = v.size();
                for(l=2;l<=nl;l++)
                {
                    for(i=0;i<(nl-l+1);i++)
                    {
                        in = i;
                        fin = i+l-1;
                        flag = 0;

                        while(1)
                        {
                            if(v[in] != v[fin])
                            {
                                flag= 1;
                                break;
                            }

                            in++;
                            fin--;
                            if(in >= fin )
                                break;
                        }

                        if(flag == 0)
                            rslt++;
                    }
                }
                v.clear();
            }
        }
        printf("%lld\n",rslt);
    }
    return 0;
}
