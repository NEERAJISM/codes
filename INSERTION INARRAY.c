/*insertion in a array*/
#include<stdio.h>
int main()
{
    int ar[100],n,i,value,pos;
    printf("enter the no. of elements in the matrix\n");
    scanf("%d",&n);
    printf("enter the %d elements to be entered\n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);

    }
    printf("enter the number to be inserted and its position");
    scanf("%d %d",&value,&pos);
    for(i=(n-1);i>(pos-2);i--)
    {
        ar[i]=ar[i+1];
    }
    ar[pos-1]=value;
    printf("the new array is ");
    for(i=0;i<(n+1);i++)
    {
        printf("%d  ",ar[i]);
    }
    return 0;
}
