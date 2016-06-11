#include<stdio.h>
#define mod 1000000007
long long int a[101],b[101][2];
int main()
{
    int n,i,top=0,count=0;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",a[i]);
        if(a[i]<0)
        {
            b[top][0]=a[i];
            b[top][1]=i;
            top++;
        }
    }

    while(top-->=0)
    {
        for(i=b[top][1];i<n;i++)

    }

}
