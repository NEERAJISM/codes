#include<stdio.h>
int main()
{
    int t,n,i,sum,a,n1;
    float d;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d",&n);
        sum=0;
        n1=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a!=0)
            {
                n1++;
                sum=sum+a;
            }
        }
        d=(sum-100);
        d=(d/n1);

        if(sum<100||d>0.9)
            printf("NO\n");
        else
            printf("YES\n");
    }
return 0;
}
