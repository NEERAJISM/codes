#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int t,l,b;
    float rmin,rmax;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&b,&l);
        b=b*b;
        l=l*l;
        rmin = sqrt(l-b);
        rmax = sqrt(l+b);

        printf("%f %f\n",rmin,rmax);
    }
    return 0;
}
