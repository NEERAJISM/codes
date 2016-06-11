/*deletion in array*/
#include<stdio.h>
int main()
{
    int a[100],i,pos,n;
    printf("enter the no. of elements in the matrix\n");
    scanf("%d",&n);
    printf("enter the %d elements to be entered\n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    printf("enter the position of number to be deleted\n");
    scanf("%d",&pos);
    for(i=(pos-1);i<n;i++)
    {
        a[i]=a[i+1];
    }
printf("the new array is ");
for(i=0;i<(n-1);i++)
    printf("%d ",a[i]);
return 0;
}
