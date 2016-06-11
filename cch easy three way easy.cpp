#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int i,count1,j,t,r,a[3][2];
    float first,second,third;
    scanf("%d",&t);

    while(t--)
    {
        count1=0;
        scanf("%d",&r);

        for(i=0;i<3;i++)
            for(j=0;j<2;j++)
                scanf("%d",&a[i][j]);

        first = sqrt((a[0][0]-a[1][0])*(a[0][0]-a[1][0]) + (a[0][1]-a[1][1])*(a[0][1]-a[1][1]));
        second = sqrt((a[0][0]-a[2][0])*(a[0][0]-a[2][0]) + (a[0][1]-a[2][1])*(a[0][1]-a[2][1]));
        third = sqrt((a[2][0]-a[1][0])*(a[2][0]-a[1][0]) + (a[2][1]-a[1][1])*(a[2][1]-a[1][1]));

        if(first<=r)
            count1++;
        if(second<=r)
            count1++;
        if(third<=r)
            count1++;

        if(count1>=2)
            printf("yes\n");
        else
            printf("no\n");
    }
return 0;
}
