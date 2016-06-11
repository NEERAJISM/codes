#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,d,i,count1,c[101];

    cin>>t;

    while(t--)
    {
        count1 = 0;
        for(i=1;i<=100;i++)
            c[i] =0;
        cin>>n;

        for(i=1;i<=n;i++)
        {
            cin>>d;

            if(c[d]==0)
                c[d] = 1;
            else
                count1++;
        }

        cout<<n-count1<<endl;
    }
    return 0;
}
