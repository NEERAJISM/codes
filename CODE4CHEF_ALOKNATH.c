#include<stdio.h>
long long int a[22];
int main()
{
    int t,n,i,k,j,flag,l,m,count,tem,temp;
    long long int sum,max;

    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d%d",&n,&k);
        sum=0;
        flag=0;
        count=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum=sum+a[i];
        }
        if(sum%k==0&&n>=k)
        {
            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if(a[j]<a[i])
                    {
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
                }
            }
            sum=sum/k;
            if(a[n-1]<=sum)
            {
                if(a[n-1]==sum)
                {
                    l=n-2;
                    count =1;
                }
                else
                    l=n-1;

                m=0;
                while(count<k&&flag==0)
                {
                    if(a[l]==sum)
                    {
                        count++;
                        l--;
                    }
                    else
                    {
                        tem=a[l]+a[m];
                        while(tem<a[n-1]&&m<l)
                        {

                            m=m+1;
                            tem=tem+a[m];
                        }
                        if(tem!=a[n-1])
                            flag=1;
                        else
                        {
                            l--;
                            count++;
                            m++;
                        }
                    }
                }
                if(count==k)
                    flag=0;
                else
                    flag=1;
            }
            else
                flag=1;
        }
        else
            flag=1;

        if(flag==0)
            printf("yes\n");
        else
            printf("no\n");
    }
return 0;
}
