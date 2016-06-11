#include<stdio.h>
int a[10][10];
int main()
{
    int n,sum,i,j;

    scanf("%d",&n);
    if(n==1)
    {
        printf("1");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        a[i][0]=1;
        a[0][i]=1;
    }

    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }

    printf("%d",2*a[n-2][n-1]);
return 0;

}
