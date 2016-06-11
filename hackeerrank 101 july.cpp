#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,x,y;

    set<  pair<int,int> > s;

    for(i=0;i<5;i++)
    {
        scanf("%d%d",&x,&y);
        s.insert(make_pair(x,y));
    }

    set<pair<int,int> >:: iterator it1 = s.begin();

    x=it1->first;
    y=it1->second;

    it1++;

    int flag=0;

    for(i=0;i<4;i++)
    {
        if(it1->first > x && it1->second > y)
        {
            flag =1;
            x=it1->first;
            y=it1->second;
        }
        else
        {
            flag=0;
            break;
        }
        it1++;
    }

    if(flag==0)
        printf("0");
    else
        printf("1");

return 0;
}
