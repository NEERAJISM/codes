#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i,j,n,m,val1,val2,a[16][16],x,y,tmp1,tmp2,k,v[226][2],lol=0,cost,x1,y1,flag1,flag2;
    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)
    {
        cin>>s;
        for(j=1;j<=m;j++)
        {
            if(s[j-1] == 'G')
            {
                a[i][j] = 1;
                v[lol][0] = i;
                v[lol][1] = j;
                lol++;
            }
            else
                a[i][j] = 0;
        }
    }
    //if(((i-tmp)>=1 )&&( (i+tmp)<=n )&&( (j-tmp)>=1 )&& ((j+tmp)<=m)  && (a[i+tmp][j]==1) && (a[i-tmp][j]==1 )&& (a[i][j-tmp] == 1) && (a[i][j+tmp] == 1))

    for(i=0;i<lol;i++)
    {
        x = v[i][0];
        y = v[i][1];
        for(j=i+1;j<lol;j++)
        {
            x1 = v[j][0];
            y1 = v[j][1];
            val1 = 0;
            val2 = 0;
            flag1 = 0;
            flag2 = 0
            tmp1 = 1;
            tmp2 = 1;

            while(1)
            {
                if(x+tmp1==0 && )

                if(((i-tmp)>=1 )&&( (i+tmp)<=n )&&( (j-tmp)>=1 )&& ((j+tmp)<=m)  && (a[i+tmp][j]==1) && (a[i-tmp][j]==1 )&& (a[i][j-tmp] == 1) && (a[i][j+tmp] == 1))
                    tmp++;
                else
                    break;
            }
        }
    }

    printf("%d",cost);
    return 0;
}
