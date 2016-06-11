#include<stdio.h>
int main()
{
    int t,n,k,l,i,j;

    scanf("%d",&t);

    while(t-->0)
    {
        scanf("%d",&n);
        k=0;
        l=n-1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(j==k||j==l)
                    printf("X");
                else
                    printf("0");

            }
            k++;
                l--;
            printf("\n");
        }
    }

    return 0;
}
