#include <iostream>
#include <cstdio>
#include <cmath>
long long int chamber[100],power[100];

using namespace std;
int main()
{
    long long int a,n,k,i,j,div;
    power[0] =1;
    scanf("%lld%lld%lld",&a,&n,&k);
    n=n+1;

    for(i=1;i<k;i++)
        power[i] = n*power[i-1];

    for(i=k-1;i>=0;i--)
    {
        chamber[i] = (a/power[i])%n;
        a=a%power[i];
    }

    for(i=0;i<k;i++)
        printf("%d ",chamber[i]);
return 0;
}
