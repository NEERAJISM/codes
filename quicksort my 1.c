#include<stdio.h>
int b[100];
void quicksort(int first,int last)
{
    if(first<last)
    {
        int temp,a,b1,pivot;
        a=first;
        b1=last;
        pivot=first;
        while(a<b1)
        {
        while(b[a]<=b[pivot]&&a<last)
            a++;
        while(b[b1]>b[pivot])
            b1--;
        if(a<b1)
        {
            temp=b[a];
            b[a]=b[b1];
            b[b1]=temp;
        }
        }

        temp=b[pivot];
        b[pivot]=b[b1];
        b[b1]=temp;
        quicksort(first,b1-1);
        quicksort(b1+1,last);
    }
}
int main()
{
    int i,n;
    scanf("%d",&n);         //size of the array

    for(i=0;i<n;i++)
        scanf("%d",&b[i]);

    quicksort(0,n-1);

    for(i=0;i<n;i++)
        printf("%d ",b[i]);

return 0;
}
