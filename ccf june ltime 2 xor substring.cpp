#include <iostream>
#include <cstdio>
using namespace std;
unsigned int a[72][72],maxxor,temp;

int main()
{
    int t,n,i,j,i1,j1,i2,j2;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);

        maxxor = 0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(i1=i;i1<n;i1++)
                {
                    for(j1=j;j1<n;j1++)
                    {
                        temp = 0;
                        for(i2=i+1;i2<=i1;i2++)
                        {
                            for(j2=j+1;j2<=j1;j2++)
                            {
                               temp = temp ^ a[i2][j2];
                            }
                        }

                        if(temp>maxxor)
                            maxxor = temp;
                    }
                }
            }
        }
        printf("%d\n",maxxor);
    }
return 0;
}
