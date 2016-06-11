#include<bits/stdc++.h>
using namespace std;

int t,x,y,x1,y1,count1=0;
void chess(int x,int y)
{
    if(x<x1&&y<y1)
    {
        if(x!=x1&&y!=y1)
        {
            cout<<"/*/*"<<endl;
            count1++;
            chess(x+2,y+1);
            chess(x-2,y+1);
            chess(x+2,y-1);
            chess(x-2,y-1);
            chess(x+1,y+2);
            chess(x-1,y-2);
            chess(x+1,y+2);
            chess(x-1,y-2);
        }
        else
            return ;
    }

}

int main()
{
    int v,w;
    cin>>t;

    while(t-->0)
    {
        cin>>x>>y>>x1>>y1;
        x1=x>x1?x-x1:x1-x;
        y1=y>y1?y-y1:y1-y;

        chess(0,0);
        cout<<3*count1<<endl;
    }
return 0;

}
