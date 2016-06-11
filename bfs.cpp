#include <iostream>
using namespace std;
int b[101];
int main()
{
    int n,a[101][101],i,j,count1 = 0,confirmed = 0,flag;
    cin>>n;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];

    for(i=1;i<=n && confirmed<=n;i++)
    {
        if(b[i] == 0)
        {
            flag = 0;

            for(j=1;j<=n && confirmed <=n;j++)
            {
                if(i!=j)
                {
                    if(a[i][j]== 1 )
                    {
                        b[i] = 1;
                        confirmed++;
                        flag= 1;
                        break;
                    }
                    else if(a[i][j] == 2)
                    {
                        b[j] = 1;
                        confirmed++;
                    }
                    else if(a[i][j] == 3)
                    {
                        b[j] =1;
                        b[i] =1;
                        flag =1;
                        confirmed += 2;
                        break;
                    }
                }
            }

            if(flag == 0)
            {
                confirmed++;
                count1++;
            }
        }
    }

    //cout<<confirmed<<endl;
    cout<<count1<<endl;

    for(i=1;i<=n;i++)
        if(b[i]==0)
            cout<<i<<" ";

    return 0;
}
