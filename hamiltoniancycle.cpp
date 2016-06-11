//hamiltonian cycle
#include<iostream>
using namespace std;
int x[10],n,m,k,g[10][10];
int place(int k)   //to select next node
{
    while(1)
    {
        int i=0;
        x[k]=(x[k]+1)%(n);      //assignment of nextnode

        if(x[k]==0)
            return 0;

        if(g[x[k-1]][x[k]]!=0)          // check if the edge exist or not
        {
            for(i=0;i<k;i++)
            {
                if(x[k]==x[i])
                    break;
            }
        }

        if(i==k)
        {
            if(k<n-1||(k==n-1&&g[0][n-1]))          //if the node is next node
                return 0;
        }
    }
}

int hamiltonian(int k)
{
    while(1)
    {
        place(k);
        if(x[k]==0)
            break;

        if(k==n-1)                      //if the cycle is complete
        {

            for(int i=0;i<n;i++)
            {
                 cout<<x[i]<<" ";
            }
            cout<<"\n"<<endl;
        }
        else
            hamiltonian(k+1);
    }
}
int main()
{
    cout<<"enter the no. of nodes of the graph\n";
    cin>>n;
    cout<<"enter the graph values\n";

    for(int i=0;i<n;i++)                    //set the graph
        for(int j=0;j<n;j++)
            cin>>g[i][j];

    cout<<"all possible hamiltonian paths are\n";
    hamiltonian(1);

    if(x[k]==0)
        for(int i=0;i<k;i++)            //print if the nopde doesn't complete
            cout<<x[i]<<" ";

    return 0;
}
