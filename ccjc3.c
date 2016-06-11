#include<stdio.h>
int main()
{
    int t,c[100001][2002],d[10000][2],add,i,bmax,j,count,save,n,a,b;
    scanf("%d",&t);
    while(t-->0)
    {
        bmax=0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&d[i][0],&d[i][1]);
            bmax=bmax>d[i][1]?bmax:d[i][1];

            for(j=0;j<=bmax;j++)
            {
                if(j>=d[i][0]&&j<=d[i][1])
                    c[i][j]=1;
                else
                    c[i][j]=0;
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<=bmax;j++)
                printf("%d ",c[i][j]);
                printf("\n");
        }
        for(i=0;i<=bmax;i++)
        {
            add=0;
            for(j=0;j<n;j++)
                add=add+c[j][i];

            c[n][i]=add;
        }
        count=0;
        for(i=0;i<n;i++)
        {
            if(c[i][bmax+1]==0)
            {
                a=d[i][0];
                b=d[i][1];
                add=0;
                for(j=a;j<=b;j++)
                {
                    if(c[n][j]>add)
                    {
                        add=c[n][j];
                        save=j;
                    }
                }
                for(j=i;j<n;j++)
                {
                    if(c[j][save]==1)
                        c[j][bmax+1]=1;
                }
                count++;
            }
        }
    printf("%d\n",count);
    }
return 0;
}
