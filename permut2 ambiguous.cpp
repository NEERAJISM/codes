#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,a[100001],flag,i,temp;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;

        flag= 0;

        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);

        for(i=1;i<=n;i++)
        {
            if(a[a[i]] != i)
            {
                flag =1 ;
                break;
            }
        }

        if(flag ==1)
            printf("not ambiguous\n");
        else
            printf("ambiguous\n");
    }
return 0;
}
