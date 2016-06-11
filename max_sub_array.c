#include<stdio.h>
fmcs(int *a,int low,int mid,int high,int *max_left,int *max_right,int *cross)
{
     int left_sum = -789654,sum=0,i,right_sum = -789654,c_sum;
     for(i=mid;i>=low;i--)
     {
         sum = sum+a[i];
         if(sum > left_sum)
         {
             left_sum = sum;
             *max_left = i;

         }
     }

     for(i=mid+1,sum = 0;i<=high;i++)
     {
         sum = sum+a[i];
         if(sum>right_sum)
         {
             right_sum = sum;
             *max_right = i;
         }
     }

     *cross = left_sum + right_sum;

}
fms(int *a,int low,int high,int *left_low,int *left_high,int *left_sum)
{
    if(low == high)
    {
        *left_low = low;
        *left_high = high;
        *left_sum = a[low];
        return;
    }
    else
    {   int right_low,right_high,right_sum,cross_low,cross_high,cross_sum,mid;

        mid = (low+high)/2;
        fms(a,low,mid,left_low,left_high,left_sum);
        fms(a,mid+1,high,&right_low,&right_high,&right_sum);
        fmcs(a,low,mid,high,&cross_low,&cross_high,&cross_sum);

        if(*left_sum>=right_sum && *left_sum>=cross_sum)
            return;
        else if(right_sum>=*left_sum && right_sum>=cross_sum)
        {
            *left_low=right_low;
            *left_high=right_high;
            *left_sum=right_sum;
        }
        else
        {
            *left_low=cross_low;
            *left_high=cross_high;
            *left_sum=cross_sum;
        }
    }
}

int main()
{
    int n,a[50],i,low=0,high=0,sum=0;
    printf("enter the no of elements in the array");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    fms(a,0,n-1,&low,&high,&sum);
    printf("%d %d %d",low,high,sum);
}
