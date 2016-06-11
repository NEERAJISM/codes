#include<stdio.h>
#include<math.h>
int a[10000000],c[10000000];      //initialise  value ==0
int main()
{
    int n,i,j,l,h,m;
    a[0]=1;
    a[1]=1;
    for(i=3;i<=sqrt(10000);i+=2)         //we are skipping all odd valuesmi
    {
        if(a[i]==0)
        {
            for(j=i*i;j<=1000000;j+=i*2)
                a[j]=1;
        }
    }

    scanf("%d%d",&l,&m);
    if(l%2==0)
    {
        for(i=0;i<=m;i+=2)
            c[i]=1;
    }
    else
    {
        for(i=1;i<=m;i+=2)
            c[i]=1;
    }

    for(i=3;i<sqrt(m);i+=2)
    {
        if(a[i]==0)
        {
            if(l%i==0)
            {
                for(j=0;j<=m;j+=i)
                    c[j]=1;
            }
            else
            {
                h=i-l%i;
                for(j=h;j<=m;j+=i)
                    c[j]=1;
            }
        }
    }

    for(i=0;i<=m;i++)
    {
        if(c[i]==0)
            printf("%d ",l+i);
    }
return 0;
}
