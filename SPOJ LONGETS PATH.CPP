#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int n,i,j,x,y,longestpath = -1;
    scanf("%d",&n);

    vector<vector<int>> v(n+1);

    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(i=1;i<=n;i++)
    {
        stack<int> s;
        vector<bool> vbool(n+1,false);

        s.push(i);
        vbool[i] = false;
        temp = 1;
        flag = 0;

        while(flag==0)
        {
            for(i=0;i<v[s.top()].size();i++)
            {

            }
        }


    }




}

