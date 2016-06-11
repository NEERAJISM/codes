#include<stdio.h>
int main()
{
    unsigned int t,i,count,j,temp,n,a[100000];
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);

        count=0;
        i=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                count++;
                temp=a[i];
                for(j=i;j<n;j++)
                {
                    if(a[j]==temp)
                        a[j]=0;
                }
            }
        }
        printf("%lld\n",count);
    }
return 0;
}
