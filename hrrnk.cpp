#include <bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define ll  long long
#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=s;i>=e;i--)
int main()
{
    int i,j,k,n,m,ttt,a1[1003],d[1003],flag,a,b,c;

    scanf("%d",&ttt);
    while(ttt--)
    {
        scanf("%d",&n);

        fp(i,1,n)
        {
            scanf("%d",&a1[i]);

            if(a1[i] >= i)
                d[i] = a1[i]-i;
            else
                d[i] = -(i - a1[i]);
        }

        while(1)
        {
            flag = 0;
            for(i=1;i<=n-2;i++)
            {
                if(d[i] >= 1)
                {
                    a = d[i]-2;
                    b = d[i+1]-1;
                    c = d[i+1]-1;
                    d[i] = b;
                    d[i+1] = c;
                    d[i+2] = a;
                    i-1;
                }
            }

            if(flag == 0)
                break;
        }

            flag = 0;
            for(i=1;i<=n;i++)
                if(d[i]!=0)
                {
                    flag = 1;
                    break;
                }

            if(flag == 0)
                printf("YES\n");
            else
                printf("NO\n");

    }
    return 0;
}


