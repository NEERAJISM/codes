#include<stdio.h>
#include<stdlib.h>
int main()
{
    signed int T,n,j,sum,b,f;
    scanf("%d",&T);
    while(T>0)
    {
        scanf("%d",&n);
        int *d=(int*)malloc(n*sizeof(int));

        for(j=0;j<n;j++)
        scanf("%d",&d[j]);

        sum=0;
        for(j=0;j<n;j++)
        {
            if(d[j]<0)
            {
                d[j]=-d[j];

                b=j-1;
                f=j+1;
                while(d[j]!=0)
                {
                    while(d[j]!=0&&d[b]>0&&b>=0)
                    {
                        if(d[b]>=d[j])
                        {
                            sum=sum+(d[j]*(j-b));

                            d[b]=d[b]-d[j];
                            d[j]=0;
                            break;
                        }

                        else
                        {
                            sum=sum+(d[b]*(j-b));

                            d[j]=d[j]-d[b];
                            d[b]=0;
                        }

                        break;
                    }
                    while(d[j]!=0&&d[f]>0&&f<n)
                    {
                        if(d[f]>=d[j])
                        {
                            sum=sum+(d[j]*(f-j));

                            d[f]=d[f]-d[j];
                            d[j]=0;
                            break;
                        }

                        else
                        {
                            sum=sum+(d[f]*(f-j));

                            d[j]=d[j]-d[f];
                            d[f]=0;
                        }

                        break;
                    }
                    if(d[j]==0)
                    break;
                    b--;
                    f++;
                }
            }
        }

        printf("%d\n",sum);
        T=T-1;
    }
return 0;
}


