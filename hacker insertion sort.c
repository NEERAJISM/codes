#include<stdio.h>
int main()
{
    int a[100000],temp,k,i,n,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            temp= a[i];
            j=i-1;
            while(a[j]>temp&&j>=0)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=temp;
        }
        for(k=0;k<n;k++)
            printf("%d ",a[k]);

        printf("\n");
    }

return 0;
}
