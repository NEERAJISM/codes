#include <iostream>
#include <cstdio>
int a[70][70];
using namespace std;

long long int findxor(int x1,int y1,int x2,int y2,long long int value)
{

}

int main()
{
    long long int max1,maxitem;
    int t,n,i,j,x,y;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        maxitem = -1;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%lld",&a[i][j]);

                 if(a[i][j]>maxitem)
                 {
                     maxitem = a[i][j];
                     x=i;
                     y=j;
                 }
            }
        max1 = findxor(x,y,x,y,maxitem);
    }
return 0;
}
