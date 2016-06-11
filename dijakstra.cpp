//dijakstra

#include<iostream>
#include<climits>
using namespace std;
int n,g[10][10];

int minfind(int *d1,bool* s1)
{
    int  u=INT_MAX,v;

    for(int i=0;i<n;i++)
    {
        if(d1[i]<=u&&s1[i]==false)
        {
            v=i;
            u=d1[i];
        }
    }
    return v;
}

void dij(int src)
{
    int distance[n];
    bool stsp[n];

    for(int i=0;i<n;i++)
    {
        stsp[i]=false;
        distance[i]=INT_MAX;
    }

    distance[src]=0;

    for(int i=0;i<n-1;i++)
    {
        int u=minfind(distance,stsp);

        stsp[u]=true;

        for(int j=0;j<n;j++)
        {
            if(stsp[j]==false&&g[i][j]>0&&distance[i]!=INT_MAX&&distance[j]>distance[i]+g[i][j])
            {
                distance[j]=distance[i]+g[i][j];
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }

}
int main()
{
    int i,j,src1;

    cout<<"enter the no. of vertex the graph\n";

    cin>>n;

    cout<<"enter the values in graph\n";

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>g[i][j];

    cout<<"enter the source vertex\n";
    cin>>src1;

    dij(src1);
}

