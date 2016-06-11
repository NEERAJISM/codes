#include<stdio.h>
int main()
{
    int a[10]={ 2,1,5,3,9,4,7,6,0,8},b[10],lower[10],upper[10],beg=0,end=9,ptr=0,top=1,left,right,temp;
    right=end;

    while(a[ptr]=<a[right]&&right!=ptr)
    {
        right--;
    }
    if(ptr==right)
    {
        b[ptr]=a[ptr];
    }
    else if(a[right]<a[ptr])
    {
        temp=a[right];
        a[right]=a[ptr];
        a[ptr]=temp;
        ptr=right;
    }


