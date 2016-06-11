#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j,flag,k;

    cin>>n>>m;
    flag=0;
    for(i=1;i<=n;i++)
    {

            if(i%2==1)
            {
                for(k=1;k<=m;k++)
                    cout<<'#';


            }
            else
            {
                if(flag==0)
                {
                    for(k=1;k<m;k++)
                    cout<<'.';

                    cout<<'#';
                    flag=1;
                }
                else
                {
                    cout<<'#';
                    for(k=2;k<=m;k++)
                    cout<<'.';
                    flag=0;
                }
            }
            cout<<endl;


    }

    return 0;

}
