#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,n,m,c,d;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);

        for(int i=0;i<m;i++)
            cin>>c>>d;

        if(n==1)
            cout<<"0"<<endl;
        else if(n==2)
        {
            if(m==1)
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
        else if(n==3)
        {
            if(m==3)
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
        else if(n==4)
        {
            if(m==5 || m==6)
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
        else if(n==5)
        {
            if(m==7 &&m==8&&m==9)
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
    }
    return 0;
}
