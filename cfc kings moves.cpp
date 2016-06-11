#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int moves;
vector<string> v;
void findpath(int x,int y,int x1,int y1)
{ moves++;
    if(x==x1 && y==y1)
        return;

    if(x1>x && y1<y)
    {
        v.push_back("RD");
        findpath(x+1,y-1,x1,y1);
    }
    else if(x1<x && y1>y)
    {
        v.push_back("LU");
        findpath(x-1,y+1,x1,y1);
    }
    else if(x1<x && y1<y)
    {
        v.push_back("LD");
        findpath(x-1,y-1,x1,y1);
    }
    else if(x1>x && y1>y)
    {
        v.push_back("RU");
        findpath(x+1,y+1,x1,y1);
    }
    else if(x1==x && y1<y)
    {
        v.push_back("D");
        findpath(x,y-1,x1,y1);
    }
    else if(x1==x && y1>y)
    {
        v.push_back("U");
        findpath(x,y+1,x1,y1);
    }
    else if(x1>x && y1==y)
    {
        v.push_back("R");
        findpath(x+1,y,x1,y1);
    }
    else if(x1<x && y1==y)
    {
        v.push_back("L");
        findpath(x-1,y,x1,y1);
    }
}

int main()
{
    int i,j,x,y,x1,y1;

    string s,d;
    cin>>s>>d;

    x = (int)s[0] -(int)'a' +1;
    y = (int)s[1] -(int)'1' +1;

    x1 = (int)d[0] -(int)'a' +1;
    y1 = (int)d[1] -(int)'1' +1;

    moves = 0;
    //cout<<x<<" "<<y<<" "<<x1<<" "<<y1<<endl;
    findpath(x,y,x1,y1);

    printf("%d\n",moves-1);

    for(i=0;i<v.size();i++)
        cout<<v[i]<<endl;

return 0;
}
