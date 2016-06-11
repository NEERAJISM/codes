#include<stdio.h>
#include<limits.h>
int a[100],leftsum,low1,high1,a1,b,rightsum,crosssum,sum,low,mid,high,p;
int maxsubarray(int low,int high)
{
    if(low==high&&a[low]%p==0)
        return a[low];
    else
    {
        mid=(low+high)/2;

        leftsum  =maxsubarray(low,mid);
        rightsum =maxsubarray(mid+1,high);
        crosssum =maxcrossarray(low,mid,high);

        if(leftsum>rightsum&&leftsum>crosssum)
            {
                sum=leftsum;
                a1=low;
                b=mid;

            }
        else if(rightsum>leftsum&&rightsum>crosssum)
            {
                sum=rightsum;
                a1= mid+1;
                b=high;
            }
        else
        {
            sum=crosssum;
            a1=low1;
            b=high1;
        }
            return sum;
    }
}
int maxcrossarray(int low1,int mid1,int high1)
{
    int j,sum1=0;
    int left_sum=INT_MIN,right_sum=INT_MIN;

    for(j=mid1;j>=low1;j--)
    {
        sum1=sum1+a[j];
        left_sum=(left_sum>sum1?left_sum:sum1);
    }

    sum1=0;

    for(j=mid1+1;j<=high1;j++)
    {
        sum1=sum1+a[j];
        right_sum=(right_sum>sum1?right_sum:sum1);
    }

    sum1=left_sum+right_sum;
    return sum1;
}

int main()
{
    int i,n;

    scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        maxsubarray(0,n-1);
        printf("maximum sub array sum is :%d \n low =%d ,high=%d",sum,a1,b);

return 0;
}
