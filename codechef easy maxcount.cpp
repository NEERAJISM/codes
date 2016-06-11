#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int t,n,i,temp,max1,par;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        vector<int>  v(10001,0);

        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            v[temp]++;
        }
        max1 = 0;
        par = -1;
        for(i=0;i<10001;i++)
        {
            if((v[i]==max1 && par > i ) || v[i]>max1)
            {
                max1 = v[i];
                par = i;
            }
        }
        printf("%d %d\n",par,max1);
    }
return 0;
}
