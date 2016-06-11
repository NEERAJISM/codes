#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t,g,i,n,q,j;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&g);

        for(j=0;j<g;j++)
        {
            scanf("%d%d%d",&i,&n,&q);

            if(n%2==0)
                printf("%d\n",n/2);
            else
            {
                if(i==q)
                    printf("%d\n",n/2);
                else
                    printf("%d\n",n/2+1);
            }
        }
    }
return 0;
}

