#include <bits/stdc++.h>
using namespace std;
int a[501][501];
int main()
{
    int x,y,i,j,n,m,d,flag,k,cnt;
    scanf("%d%d",&n,&m);
    vector< vector<int> > v(n+1);
    vector<char> vt(n+1,'*');



    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for(i=2;i<=n;i++)
        for(j=1;j<i;j++)
            if(a[i][j] == 0)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }

    flag = 0;
    for(i=1;i<=n;i++)
    {
        if(v[i].size() > 2)
        {
            cnt = 0;
            for(j=0;j<v[i].size();j++)
            {
                for(k=j+1;k<v[i].size();k++)
                {
                    if(a[j][k] == 0)
                    {
                        cnt+=1;
                    }

                    if(cnt == 2)
                    {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 1)
                    break;
            }

            if(flag == 1)
                break;

            if(cnt == 1)
            {
                if(v[i] == '*')
                    v[i] = 'b';
                else
                {
                    flag = 1;
                    break;
                }

                for(j=0;j<v.size();j++)
                    if(v[j] == '*')

            }
        }
    }

    if(flag == 1)
        printf("No");
    else
    {
        printf("Yes\n");

        for(i=1;i<=n;i++)
            printf("%c",vt[i]);
    }
    return 0;
}
