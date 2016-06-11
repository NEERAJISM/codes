#include <iostream>
#include <cstdio>
#define mod 1000000007
int fact(int x)
{
    int result=1;
    for(int i=1;i<=x;i++)
        result= (result*i)%mod;

    return result;
}
using namespace std;
int main()
{
    int n,c,i,a[1001],sum;
    scanf("%d",&c);
    n=0;

    for(i=0;i<c;i++)
    {
        scanf("%d",&a[i]);
        n+=a[i];
    }

    a[c-1]--;
    a[c-2]--;

    sum = fact(n-2);

    for(i=0;i<c;i++)
    {
        sum = sum/fact(a[i]);
    }

    printf("%d\n",sum);
return 0;
}
