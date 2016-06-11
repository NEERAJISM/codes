#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,k,n,m,ttt,t,res,b,a,flag,op;
    stack<long long int> st;
    long long int c[4],s[16],cc;
    c[0] = -1; // /
    c[1] = -2; // *
    c[2] = -3; // +
    c[3] = -4; // -


    for(j=0;j<4;j++)
        for(i=0;i<4;i++)
            s[4*j+i] = c[(i+j)%4];

    scanf("%lld",&ttt);
    while(ttt--)
    {
        scanf("%lld",&n);
        res = 0;

        scanf("%lld",&res);

        if(n==1)
            printf("%lld\n",cc);
        else
        {
            for(i=1;i<n;i++)
            {
                scanf("%lld",&b);

                if(s[(i-1)%16] == -1)
                    res/=b;
                else if(s[(i-1)%16] == -2)
                    res*=b;
                else if(s[(i-1)%16] == -3)
                    res+=b;
                else
                    res-=b;
            }

            printf("%lld\n",res);
        }
    }

    return 0;
}
