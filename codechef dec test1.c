#include<stdio.h>
int main()
{
    unsigned int t,i,k,count,j,flag,n,a[100000],b[100000];
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        count=0;
        k=0;
        for(i=0;i<n;i++)
        {
            flag=0;
            if(k==0)
            {
                b[k]=a[i];
                k++;
                count++;
            }
            else
            {
                for(j=0;j<k;j++)
                {
                    if(b[j]==a[i])
                    {
                        flag=1;
                        break;
                    }
                }
                    if(flag==0)
                    {
                        b[k]=a[i];
                        k++;
                        count++;
                    }
            }
        }
        printf("%d\n",count);
    }
return 0;
}
