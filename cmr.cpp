#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,ttt,n,na,nb,tmp,flag,i1,c,x,y;
    vector<int> v(100005,0);
    set<int> s;
    scanf("%d",&ttt);

    while(ttt--)
    {
        scanf("%d%d",&n,&c);

        for(i=0;i<c;i++)
        {
            scanf("%d%d",&x,&y);
            v[x]++;
            v[y]++;
        }

        for(i=1;i<=n;i++)
            s.insert(v[i]);

        if(s.size() > 2)
            printf("No\n");
        else
        {
            vector<int> v1(s.begin(),s.end());

            if(v1[0] != 3)
                printf("No\n");
            else
                printf("Yes\n");
        }
        v.clear();
    }

    return 0;
}
