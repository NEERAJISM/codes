#include<iostream>
#include<cmath>
using namespace std;
int x[100],n;

bool check(int c,int r)
{

    for(int j=0;j<c;j++)
    {
        if(x[j]==r||abs(x[j]-r)==abs(j-c))
            return false;
    }
    return true;
}
bool queen(int col)
{
    if(col==n)
    {
        for(int i=0;i<n;i++)
            cout<<x[i]<<" ";
        return true;
    }

    for(int i=0;i<n;i++)
    {
        if(check(col,i))
        {
            x[col]=i;

            if(queen(col+1)==true)
                return true;
        }
    }
    return false;
}
int main()
{
    cin>>n;
    queen(0);
    return 0;
}
