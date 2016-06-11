#include<stdio.h>
#include<limits.h>
int main()
{
    int a[100],left,right,i,n,j,max,sum;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    max=INT_MIN;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
            sum=sum+a[j];

        if(max<sum)
        {
            max=sum;
            left=i;
            right=j;
        }
    }

    printf("max=%d,left= %d,right=%d",max,left+1,right+1);

return 0;
}
