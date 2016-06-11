#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,coin;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);

        if(n==1 || k==1)
            printf("0\n");
        else if(k>n)
            printf("%d\n",n);
        else
        {
            coin = 0;
            int max1 =-1;

            for(int i=2;i<=k;i++)
            {
                int temp = n%i;

                if(temp>max1)
                    max1 =temp;
            }
            printf("%d\n",max1);
        }
    }
return 0;
}

