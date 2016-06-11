#include<stdio.h>
int a[100000];
quick(int first ,int last)
{
    int pivot,temp,i,j;
    pivot=first;
    i=first;
    j=last;
    while(i<j)
    {
        while(a[i]<=a[pivot]&&i<last)
            i++;
        while(a[j]>a[pivot])
            j--;

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }

        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quick(first,j-1);
        quick(j+1,last);
    }
}
int main()
{
   int n,i,j,temp,k,min;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    quick(0,n-1);

    i=k-1;
    j=0;
    min=a[i]-a[j];
    for(i=k-1,j=0;i<n;i++,j++)
        min=(min<(a[i]-a[j])?min:(a[i]-a[j]));

    printf("%d",min);
return 0;
}

