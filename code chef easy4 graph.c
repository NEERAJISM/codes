#include<stdio.h>
int main()
{
    int t,count,i,j,n,x,y,m,a[100][2];

    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            for(j=0;j<2;j++)
                scanf("%d",&a[i][j]);
        }
        if(n%2!=0)
            printf("NO\n");
        else
        {
            for(i=0;i<m;i++)
            {
                if(a[i][0]!=0)
                {
                    x=a[i][0];
                    y=a[i][1];

                    for(j=i+1;j<m;j++)
                    {
                        if(a[j][0]!=0)
                        {
                            if(a[j][0]==x||a[j][1]==x||a[j][0]==y||a[j][1]==y)
                            {
                                a[j][0]=0;
                                a[j][1]=0;
                            }
                        }
                    }
                }
            }
            count=0;
            for(i=0;i<m;i++)
            {
                if(a[i][0]!=0)
                    count++;
            }

            if(n/2==count)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
return 0;
}
