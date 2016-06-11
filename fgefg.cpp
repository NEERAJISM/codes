#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,q,x,y,k,dummy[100005],i,j,i1,a[100005];
    char c;
    scanf("%d%d",&n,&q);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    sort(a+1,a+n);

    for(i=0;i<n;i++)
        printf("%d",a[i]);
return 0;
}
