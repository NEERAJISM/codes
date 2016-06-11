#include<stdio.h>
int a[1000000];
void quick(int first,int last)
{
    if(first<last)
    {
        int temp,i,j,p;

        i=first;
        j=last;
        p=first;

        while(i<j)
        {
            while(a[i]<=a[p]&&i<last)
                i++;
            while(a[p]<a[j])
                j--;

            if(i<j)
            {
                temp =a[i];
                a[i]= a[j];
                a[j]=temp;
            }
        }
        temp = a[j];
        a[j]=a[p];
        a[p]=temp;
        quick(first,j-1);
        quick(j+1,last);
    }
}
int main()
{
    int i,n;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    quick(0,n-1);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
