#include<stdio.h>
int* quick(int* a ,int low,int high)
{
    if(low<high)
    {
        int  i=low,j=high,p=low,temp;
        while(i<j)
        {
            while(a[i]<=a[p]&&i<high)
                i++;

            while(a[p]<a[j])
                j--;

            if(i<j)
            {
                temp= a[i];
                a[i] =a[j];
                a[j] =temp;
            }
        }

        temp=a[j];
        a[j]=a[p];
        a[p]=temp;

        quick(a,low,j-1);
        quick(a,j+1,high);

        return (&a[low]);
    }
}
int main()
{
    int n,a[100],i;

    scanf("%d",&n);

    for(i=0;i<n;i++)
            scanf("%d",&a[i]);

    quick(a,0,n-1);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
