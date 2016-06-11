#include<iostream>
using namespace std;
int main()
{
    int t,n,x,y,k,a,b,i,j,p[100000][2];

    cin>>t;
    while(t--)
    {
        cin>>x>>y>>k>>n;
        j=0;
        for(i=0;i<n;i++)
        {
            cin>>a>>b;                  //a=p&&b==c
            if(b<=k)
            {
                p[j][1]=a;
                p[j][2]=b;
                j++;
            }
        }
        n=j;
        a=x-y;
        b=0;
        for(i=0;i<n;i++)
        {
            if(p[i][1]>=a)
            {
                b=1;
                break;
            }
        }

        if(b==1)
            cout<<"LuckyChef\n";
        else
            cout<<"UnluckyChef\n";
    }
return 0;
}
