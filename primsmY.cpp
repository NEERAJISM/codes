//PRIMS BY MATRIX

#include<iostream>
#include<climits>
using namespace std;
int n,g[10][10];
void printg(int* p)
{
    cout<<"edge"<<" "<<"weight"<<endl;

    for(int i=0;i<n;i++)
        cout<<p[i]<<" "<<g[i][p[i]]<<endl;

}

int minkey(int* key1,bool* mst1)
{
    int u2,min1=INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(mst1[i]==false&&key1[i]<min1)
        {
            min1=key1[i];
            u2=i;
        }
    }
    return u2;
}

void graph()
{
    int parent[n],key[n];
    bool mst[n];

    for(int i=0;i<n;i++)                         // initializing the array
    {
        mst[i]=false;
        key[i]=INT_MAX;
    }
    key[0]=0;
    parent[0]=-1;


    for(int i=0;i<n-1;i++)
    {
        int u = minkey(key,mst);              //finding the minimum key value
        mst[u]=true;
        for(int v=0;v<n;v++)
        {
            if(g[u][v]>0&&g[u][v]<key[v]&&mst[v]==false)
                parent[v]=u,key[v]=g[u][v];
        }
    }

    printg(parent);

}

int main()
{
    int i,j;

    cin>>n;
    cout<<"enter the values of the graph matrix"<<endl;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>g[i][j];

    graph();

return 0;

}
