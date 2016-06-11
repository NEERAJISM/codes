#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,rslt,a[101];
    a[1] = 1;
    for(i=2;i<=100;i++)
        a[i] = a[i-1] + i*i;

    while(1)
    {
        scanf("%d",&n);

        if(n == 0)
            break;
        else
            printf("%d\n",a[n]);
    }
    return 0;
}
