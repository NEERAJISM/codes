#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    float with,bal;

    scanf("%f",&with);
    scanf("%f",&bal);

    //printf("%d\n",(int)with%5);

    if(with+0.5<bal && (int)with%5==0)
        printf("%f\n",bal-with-0.5);
    else
        printf("%f\n",bal);
    return 0;
}
