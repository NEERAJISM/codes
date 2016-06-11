#include<stdio.h>
int c[100002][2002],d[100002][2];
int main()
{
    int t,add,max,i,bmax,k,j,count,save,n,a,b;

    scanf("%d",&t);
    while(t-->0)
    {
        bmax=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&d[i][0],&d[i][1]);

            for(j=d[i][0];j<=d[i][1];j++)
                c[i][j]=1;

            bmax=bmax>d[i][1]?bmax:d[i][1];
        }
        for(i=0;i<=bmax;i++)
        {
            add=0;
            for(j=0;j<n;j++)
                add=add+c[j][i];

            c[n][i]=add;
        }

        count=0;
        while(1)
        {
            max=0;
            for(i=0;i<=bmax;i++)
            {
                if(c[n][i]>max)
                {
                    max=c[n][i];
                    save=i;
                }
            }
            if(max==0)
                break;

            count++;
            c[n][save]=1;
            for(i=0;i<n;i++)
            {
                if(c[i][save]==1)
                {
                    for(j=d[i][0];j<=d[i][1];j++)
                        c[n][j]--;
                }
            }
        }
        printf("%d\n",count);

        for(i=0;i<=n;i++)
        {
            for(j=0;j<=bmax+1;j++)
                c[i][j]=0;
        }
    }

return 0;
}
