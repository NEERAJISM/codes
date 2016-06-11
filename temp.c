#include<stdio.h>
int main()
{
   long long int T,n,j,sum,b,f,D[100001];
    scanf("%lld",&T);
    while(T>0)
    {
        scanf("%lld",&n);
        for(j=0;j<n;j++)
            scanf("%lld",&D[j]);

        sum=0;
        for(j=0;j<n;j++)
        {
            if(D[j]<0)
            {
                D[j]=-D[j];

                b=j-1;
                f=j+1;
                while(D[j]!=0)
                {
                    while(D[j]!=0&&D[b]>0&&b>=0)
                    {
                        if(D[b]>=D[j])
                        {
                            sum=sum+(D[j]*(j-b));

                            D[b]=D[b]-D[j];
                            D[j]=0;
                            break;
                        }

                        else
                        {
                            sum=sum+(D[b]*(j-b));

                            D[j]=D[j]-D[b];
                            D[b]=0;
                        }

                        break;
                    }
                    while(D[j]!=0&&D[f]>0&&f<n)
                    {
                        if(D[f]>=D[j])
                        {
                            sum=sum+(D[j]*(f-j));

                            D[f]=D[f]-D[j];
                            D[j]=0;
                            break;
                        }

                        else
                        {
                            sum=sum+(D[f]*(f-j));

                            D[j]=D[j]-D[f];
                            D[f]=0;
                        }

                        break;
                    }
                    if(D[j]==0)
                    break;
                    b--;
                    f++;
                }
            }
        }

        printf("%lld\n",sum);
        T=T-1;
    }
return 0;
}


