#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int i,t,a[10],min1,mag1;

    scanf("%d",&t);
    while(t--)
    {
        mag1= 100;
        for(i=0;i<10;i++)
        {
            scanf("%d",&a[i]);

            if(mag1 > a[i] || min1==0 && mag1==a[i])
            {
                mag1= a[i];
                min1 = i;
            }
        }

        if(min1 == 0)
        {
            printf("1");
            mag1++;
            while(mag1--)
            {
                printf("%d",min1);
            }
        }
        else
        {
            mag1++;
            while(mag1--)
            {
                printf("%d",min1);
            }
        }

        printf("\n");
    }
return 0;
}
