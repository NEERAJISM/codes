#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long long int t,n,k,sum,flag1,i,temp;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        sum = 0;

        for(i=0;i<n;i++)
        {
            scanf("%lld",&temp);
            sum+=temp;
        }

       if(sum%2==0)
        flag1=0;
       else
        flag1= 1;

       if(k==1)
       {
           if(flag1==0)
            cout<<"odd\n";
           else
            cout<<"even\n";
       }
       else
        cout<<"even\n";
    }
return 0;
}
