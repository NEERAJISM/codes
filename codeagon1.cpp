#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,sj,i,j,cnt,valp = 0,valc = 0,tmp,flag = 0,rslt = -1;
    scanf("%lld%lld",&n,&sj);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&tmp);
        if(flag == 0)
        {
            if(tmp <= sj)
                valc++;
            else
            {
                if(valc > 0)
                {
                    valp = valc;
                    valc = 0;
                    flag = 1;
                }
            }
        }
        else if(flag == 1)
        {
            if(tmp <= sj)
                valc++;
            else
            {
                if((valp+valc) > rslt)
                    rslt = valp+valc;

                valp = valc;
                9
                valc = 0;
            }
        }
    }

    if((valp+valc) > rslt)
        rslt = valp+valc;

    printf("%lld",rslt);
    return 0;
}
