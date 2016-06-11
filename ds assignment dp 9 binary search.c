#include<stdio.h>
int a[10]={1,3,5,9,12,15,17,20,23,25};
void binary(int ,int ,int,int);
int main()
{
    int i,d,num,j,n=10;
    scanf("%d",&num);
    d=(0+n-1)/2;

    binary(0,d,n-1,num);

}

void binary(int beg,int mid,int end,int item)
{

        if(a[mid]==item)
        {
            printf("the item is present in the list\n");
            return 0;
        }
        else if(item>a[mid])
            beg=mid+1;
        else if(beg==end&&a[mid]!=item)
        {   printf("the element does not exist in the array\n");
            return ;
        }
        else
            end=mid-1;

        mid=(beg+end)/2;

        binary( beg,mid,end,item);

}











