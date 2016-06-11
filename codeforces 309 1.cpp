#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int pow2[101],n,a[101],i,j,sum,count1;
    string s;

    typedef struct{
        string s;
    }input;

    scanf("%d",&n);

    input ip[n];

    for(i=0;i<n;i++)
    {
        cin>>ip[i].s;
        a[i] = 0;
    }

    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            a[i]=1;
            for(j=i+1;j<n;j++)
            {
                if(ip[i].s==ip[j].s)
                {
                    a[i]++;
                    a[j]=1;
                }
            }
        }
    }

    int max1 = -1;
    for(i=0;i<n;i++)
    {
        if(a[i]>max1)
            max1=a[i];
    }
    printf("%d\n",max1);
return 0;
}
