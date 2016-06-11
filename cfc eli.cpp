#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n,m,ttt,sm,res,com = 0,vl1,vl2,mn,tp1,tp2;
    scanf("%d%d",&m,&n);

    if(m==0)
        printf("%d",n*3);
    else if(n==0)
        printf("%d",m*2);
    else
    {
        vl1 = 2*m;
        vl2 = 3*n;
        mn = vl1<vl2?vl1:vl2;
        com = mn/6;

        if(com > 0)
        {
            while(com--)
            {
                if(vl1+2 <= vl2+3)
                    vl1+=2;
                else
                    vl2+=3;
            }
        }

        mn = vl1>vl2?vl1:vl2;
        printf("%d",mn);
    }
    return 0;
}
