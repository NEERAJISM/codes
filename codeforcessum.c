#include<stdio.h>
int main()
{
    int n,a[300],i,t;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        while(a[i]-->0)
            printf("1");

        if(i>0&&a[i-1]-a[i]>0)
        {
            t=a[i-1]-a[i];
            while(t-->0)
                printf("0");
        }
        printf("\n");
    }
    return 0;
}
