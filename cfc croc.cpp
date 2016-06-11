#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=s;i>=e;i--)
int g[1002][1002];
int main()
{
    int i,j,k,m,n,a,b,x,y,od,ev,e=2,o=1,tt,flag1=0,flag2=0,l;
    scanf("%d%d%d",&n,&a,&b);

    if(n>a*b)
        printf("-1");
    else
    {
        if(n%2 == 1)
        {
            od = n;
            ev = n-1;
        }
        else
        {
            ev = n;
            od = n-1;
        }

        for(j=1;j<=b;j++)
        {
            if(flag1 == 1 && j%2 == 1)
                continue;

            if(flag2 == 1 && j%2 == 0)
                continue;

            if(flag1+flag2 == 2)
                break;

            x = 1;
            y = j;

            if(j%2 == 0)
                tt = e;
            else
                tt = o;

            while(1)
            {
                g[x][y] = tt;
                tt+=2;

                if((tt%2 == 0 && tt> ev))
                {
                    flag2 = 1;
                    break;
                }

                if(tt%2 == 1 && tt> od)
                {
                    flag1 = 1;
                    break;
                }

                x++;
                y--;

                if(x>a || y<1)
                    break;
            }

            if(j%2 == 0)
                e = tt;
            else
                o = tt;
        }

        if(b%2 == 0)
            l = 1;
        else
            l = 0;


        for(i=2;i<=a;i++)
        {
            if(flag1 == 1 && (i+l)%2 == 1)
                continue;

            if(flag2 == 1 && (i+l)%2 == 0)
                continue;

            if(flag1+flag2 == 2)
                break;

            x = i;
            y = b;

            if((i+l)%2 == 1)
                tt = o;
            else
                tt = e;

            while(1)
            {
                g[x][y] = tt;
                tt+=2;

                if((tt%2 == 0 && tt> ev))
                {
                    flag2 = 1;
                    break;
                }

                if(tt%2 == 1 && tt> od)
                {
                    flag1 = 1;
                    break;
                }

                x++;
                y--;

                if(x>a || y<1)
                    break;
            }

            if((i+l)%2 == 1)
                o = tt;
            else
                e = tt;
        }

        fp(i,1,a)
        {
            fp(j,1,b)
                printf("%d ",g[i][j]);
            printf("\n");
        }
    }
    return 0;
}
