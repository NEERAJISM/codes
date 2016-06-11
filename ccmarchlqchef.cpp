#include<iostream>
#include<cmath>
using namespace std;
int main()
{
        int n,l,r,i,j,m,k,a[100007],c,d,cost;
        cin>>n>>m>>k;

        for(i=1;i<=n;i++)
            cin>>a[i];

        while(k--)
        {
            cin>>l>>r;
            cost=0;
            for(i=l;i<=r;i++)
            {
                    for(j=r;j>=l+1;j--)
                    {
                        if(a[j]==a[i])
                        {
                            //cout<<i<<" "<<j<<endl;
                            cost=cost>abs(i-j)?cost:abs(i-j);
                            break;
                        }
                    }
                if(cost>=r-i-1)
                    break;
            }
            cout<<cost<<endl;
        }
return 0;
}
