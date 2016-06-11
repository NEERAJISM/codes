#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int i,j;
    scanf("%d%d",&i,&j);

    if(i==0&&j==0)
        cout<<"0 0\n";
    else
    printf("%d %d",j-1,i-1);
}
