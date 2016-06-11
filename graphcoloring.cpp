#include<iostream>
using namespace std;
int x[10],n,m,g[10][10];
int place(int k)                //select new color
{
    while(1)
    {
        int i;
        x[k]=(x[k]+1)%(m+1);

        if(x[k]==0)
            return 0;

        for( i=0;i<n;i++)                   //if that color exist
            if(g[k][i]&&x[k]==x[i])
                break;

        if(i==n)
            break;

    }
}
int color(int k)
{
    while(1)
    {
        place(k);

        if(x[k]==0)                 //if no color assigned
            break;

        if(k==n-1)
        {
            for(int i=0;i<n;i++)
                 cout<<x[i]<<" ";

            cout<<endl;
            return 0;
        }
        else
            color(k+1);
    }
}
int main()
{
    cout<<"enter the no. of nodes of the graph\n";
    cin>>n;
    cout<<"enter the graph values\n";

    for(int i=0;i<n;i++)                    //enter the value in the graph
        for(int j=0;j<n;j++)
            cin>>g[i][j];

    cout<<"enter the no. of colors\n";
    cin>>m;

    color(0);
    return 0;
}
