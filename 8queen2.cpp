//8queen
#include<iostream>
#include<cmath>
using namespace std;
int n,x[100];
bool place(int k,int i)
{
    for(int j=0;j<k;j++)
    {
        if(x[j]==i||abs(x[j]-i)==abs(j-k))
        {
            return false;
        }
    }
    return true;
}

void queen(int k)
{
    for(int i=0;i<n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==(n-1))
            {
                for(int j=0;j<n;j++)
                    cout<<x[j]<<" ";

                cout<<endl;
            }
            else
                queen(k+1);
        }
    }
}
int main()
{
    cout<<"enter the size of the chess board ";
    cin>>n;
    queen(0);

    return 0;
}
