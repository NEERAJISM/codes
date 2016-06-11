#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=s;i>=e;i--)
ll int ans[200005];
int main()
{
    int i,j,k,m,tt,a,b,t[200005][2],x,y,cmp = 0,n,cnt=0;
    ll int tm = 0;
    queue<pair<int,int> > q;

    scanf("%d%d",&n,&b);

    for(i=0;i<n;i++)
        scanf("%d%d",&t[i][0],&t[i][1]);

    q.push(make_pair(t[0][0],t[0][1]));

    tm = (ll int)t[0][0];
    i = 1;
    while(1)
    {
        if(cmp >= n)
            break;

        if(q.empty()==0)
        {
            y = q.front().second;
            q.pop();

            while((cmp< n) && (ans[cmp] == -1))
                cmp++;

            ans[cmp] = tm + y;
            tm = ans[cmp];
            cmp++;
        }
        else
        {
            ans[i] = t[i][0] + t[i][1];
            tm = ans[i];
            cmp++;
            i++;
        }

        cnt = q.size();
        while((i<n) && (t[i][0] < tm))
        {
            if(cnt<b)
            {
                q.push(make_pair(t[i][0],t[i][1]));
                cnt++;
            }
            else
                ans[i] = -1;
            i++;
        }
    }

    fp(i,0,n-1)
        printf("%lld ",ans[i]);

    return 0;
}
