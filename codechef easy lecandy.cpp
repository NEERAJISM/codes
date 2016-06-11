#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t,n,i,c,sum,temp;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d",&n,&c);
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            sum+=temp;
        }

        if(sum>c)
            printf("No\n");
        else
            printf("Yes\n");
    }
return 0;
}
