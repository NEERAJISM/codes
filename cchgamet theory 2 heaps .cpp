#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&x,&y);

        if(x%2==0 || y%2==0)
            printf("Tuzik\n");
        else
            printf("Vanka\n");
    }
return 0;
}
