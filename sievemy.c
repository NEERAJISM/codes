#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[100000];
int main()
{
    int n,i,j;

    scanf("%d",&n);

    for(i=0;i<=n;i++)
        a[i]=1;

    a[0]=0;
    a[1]=0;

    for(i=3;i<=sqrt(10000000);i+=2)
    {
        if(a[i]==1)
        {
            for(j=i*i;j<=10000000;j+=2*i)
                a[j]=0;
        }
    }

    for(i=1;i<100;i++)
        if(a[i] == 1)
            printf("%d ",i);

    return 0;
}
