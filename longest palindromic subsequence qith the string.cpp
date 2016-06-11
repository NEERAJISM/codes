#include <bits/stdc++.h>
using namespace std;

int lps(char* s,int n)
{
    int i,j,len,l[n][n];

    for(i=0;i<n;i++)
        l[i][i] = 1;

    for(len=2;len<=n;len++)
    {
        for(i=0;(i+len-1)<n;i++)
        {
            j = i+len-1;

            if(s[i] == s[j] && len == 2)
                l[i][j] = 2;
            else if(s[i] == s[j])
                l[i][j] = l[i+1][j-1] + 2;
            else
                l[i][j] = max(l[i+1][j],l[i][j-1]);
        }
    }
    return l[0][n-1];
}

int main()
{
    int ttt,na,nb,la,lb,rslt;
    char a[1003],b[1003];
    scanf("%d",&ttt);

    while(ttt--)
    {
        scanf("%s",a);
        scanf("%s",b);

        na = strlen(a);
        nb = strlen(b);

        la = lps(a,na);
        lb = lps(b,nb);

        if(la%2==0 || lb%2 == 0)
        {
            if(la%2 == 1)
                la-=1;
            else if(lb% 2 == 1)
                lb-=1;
        }

        rslt = la+lb;
        printf("%d\n",rslt);
    }
return 0;
}
