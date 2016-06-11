#include <bits/stdc++.h>
using namespace std;
char a[505][505];
char s1[505];
vector<pair<int,int> > v;
int mx= 0;
int i,j,k,m,n,x,y;

void dfs(int x,int y,int len,vector<vector<int> >& bul)
{
    if(x-1 >=0 && bul[x-1][y] == 0 && a[x-1][y] == '*')
    {
        bul[x-1][y] = 1;
        dfs(x-1,y,len+1,bul);
    }

    if(x+1 < m && bul[x+1][y] == 0 && a[x+1][y] == '*')
    {
        bul[x+1][y] = 1;
        dfs(x+1,y,len+1,bul);
    }

    if(y-1 >= 0 && bul[x][y-1] == 0 && a[x][y-1] == '*')
    {
        bul[x][y-1] = 1;
        dfs(x,y-1,len+1,bul);
    }

    if(y+1 < n && bul[x][y+1] == 0 && a[x][y+1] == '*')
    {
        bul[x][y+1] = 1;
        dfs(x,y+1,len+1,bul);
    }

    if(len > mx)
        mx = len;
}


int main()
{
    int len;
    scanf("%d%d",&m,&n);

    for(i=0;i<m;i++)
    {
        scanf("%s",s1);

        for(j=0;j<n;j++)
        {
            a[i][j] = s1[j];

            if(s1[j] == '*')
            v.push_back(make_pair(i,j));
        }
    }

    for(i=0;i<v.size();i++)
    {
        x = v[i].first;
        y = v[i].second;
        vector<vector<int> > bul(501,vector<int>(501,0));
        if(bul[x][y] == 0)
        {

                bul[x][y] = 1;
                len = 1;
                dfs(x,y,len,bul);
        }
    }

    printf("%d\n",mx);
    return 0;
}
