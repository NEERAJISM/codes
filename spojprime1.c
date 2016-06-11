#include<stdio.h>
#include<math.h>
a[10000000];
int main()
{
    int t,n,m,i,add,j;

    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d%d",&n,&m);
        a[0]=1;
        a[1]=1;
        for(i=3;i<=sqrt(sqrt(n));i+=2)
        {
            if(a[i]==0)
            {
                for(j=i*i;j<=sqrt(n);j+=2*i)
                a[j]=1;
            }
        }

        for(i=3;i<sqrt(n);i+=2)
        {
            if(a[i]==0)
            {
                if(n%i==0)
                    add=n;
                else
                    add=n+i-a[i]%i;

                if(a[add]==0)
                {
                    for(j=add*add;j<=sqrt(sqrt(n));j+=2*add)
                        a[j]=1;
                }
            }
        }

        for(i=add;i<=m;i+=2)
        {
            if(a[i]==0)
                printf("%d ",i);
        }
    }
return 0;
}
