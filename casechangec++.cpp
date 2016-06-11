#include<bits/stdc++.h>
using namespace std;
char g[10][10];
int len,n,m;

set <string>li;

void find1(int x,int y,string s)
{
    if(g[x][y]=='*'||x<1||y<1||x>n||y>m)
        return ;
    if(s.size()==len)
    {
        li.insert(s);
        return ;
    }
    s=s+g[x][y];
    find1(x+1,y,s);
    find1(x,y-1,s);
    find1(x,y+1,s);
    find1(x-1,y,s);
}

int main()
{
    int x,y;
    string a;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>a;


        for(int j=0;j<m;j++)
            g[i][j]=a[j];
    }

    cin>>len>>x>>y;

    find1(x,y,"");

    for(auto e : li)
        cout<<e<<endl;

return 0;
}
