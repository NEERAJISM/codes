#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,i,a[1001],mag;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    mag = (n-a[0])%n;

    int flag=0;
    a[0] = 0;

    for(i=1;i<n;i++)
    {
        if(flag==0)
        {
            a[i] = a[i]-mag;
            if(a[i]<0)
                a[i] = n+a[i];

            flag++;
        }
        else
        {
            a[i] = a[i]+mag;
            if(a[i]>n-1)
                a[i] = a[i]%n;
            flag--;
        }

        if(a[i]!=i)
        {
            flag=-1;
            break;
        }
    }

    if(flag==-1)
        cout<<"No";
    else
        cout<<"Yes";
return 0;
}
