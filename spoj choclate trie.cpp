#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=e;i>=s;i--)

bool comp(int x,int y)
{
    if(x>y)
        return 1;

    return 0;
}

int main()
{
    int i,j,k,n,m,ttt,tmp,x,y,totx,toty,a[1001],b[1001];
    long long int cost;
    scanf("%d",&ttt);
    while(ttt--)
    {
        x = 1;
        y = 1;
        cost = 0;
        scanf("%d%d",&m,&n);

        fp(i,0,m-2)
            scanf("%d",&a[i]);

        fp(i,0,n-2)
            scanf("%d",&b[i]);

        sort(a,a+(m-1),comp);
        sort(b,b+(n-1),comp);

        i = 0;
        j = 0;

        while(1)
        {
            if((i>=(m-1)) || (j>=(n-1)))
                break;

            if(a[i] > b[j])
            {
                cost+=(a[i]*y);
                i++;
                x+=1;
            }
            else
            {
                cost+=(b[j]*x);
                j++;
                y+=1;
            }
        }

        while(i<(m-1))
        {
            cost+=a[i]*y;
            i++;
        }

        while(j<(n-1))
        {
            cost+=(b[j]*x);
            j++;
        }

        printf("%lld\n",cost);
    }
    return 0;
}
