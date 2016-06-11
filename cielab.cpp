#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a,b,temp;

    scanf("%d%d",&a,&b);

    if((a-b+1)%10==0)
        printf("%d\n",a-b-1);
    else
        printf("%d\n",a-b+1);

return 0;
}
