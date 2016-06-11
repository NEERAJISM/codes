#include <bits/stdc++.h>
using namespace std;
int a[1002][1002];
int main()
{
    int t,i,j,count1,x,y,flag1,flag2,flag3,flag4,k;
    long long int total,n;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld%d",&n,&k);

        set< pair<int,int> > s;

        total =n*n;
        if(k==0)
            printf("%lld\n",total);
        else
        {

            for(int tt= 0;tt<k;tt++)
            {
                scanf("%d%d",&x,&y);
                s.insert(make_pair(x,y));
                i=1;
                while(x+i<=n && y+i<=n)
                {
                    s.insert(make_pair(x+i,y+i));
                    i++;
                }

                i=1;
                while(x-i>0 && y-i>0)
                {
                    s.insert(make_pair(x-i,y-i));
                    i++;
                }

                i=1;
                while(x-i>0 && y+i<=n)
                {
                    s.insert(make_pair(x-i,y+i));
                    i++;
                }

                i=1;
                while(x+i<=n && y-i>0)
                {
                    s.insert(make_pair(x+i,y-i));
                    i++;
                }
            }

            printf("%lld\n",total - s.size());
        }
    }
return 0;
}
