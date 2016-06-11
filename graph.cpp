//graph basic
#include<iostream>
using namespace std;
int a[10][10];
int main()
{
    int n,v,b[10],k=0,i,j;

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>a[i][j];

    }

    b[0]=1;
    v=100;
    k++;
    int min1=1000;

    while(k<n)
    {

            a[i][0]=1;
        for(i=0;i<k;i++)
            for(j=1;j<=n;j++)
            {
                if(a[b[i]][j]<min1&&a[j][0]==0)
                    v=j;
            }
            b[k]=v;
            k++;
    }

    for(i=0;i<k;i++)
        cout<<b[k]<<" "<<endl;

    return 0;
}
