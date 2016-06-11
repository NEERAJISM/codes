/*spike's point*/
#include<stdio.h>
int main()
{
    int i,j,k,n,l=1;
    printf("ENTER THE NO. UPTO WHICH SPIKES POINT REQUIRED\n");
    scanf("%d",&n);
    if(n==0)
        printf("no spike point");
    for(i=1;i<(n+1);i++)
    {
        for(j=1;j<(n+1);j++)
        {
            for(k=l;k<(n+1);k++)
            {
                if(k*k==((j*j)+(i*i)))
                {
                    printf("%d\n",k);
                    l=k;
                    break;
                }
                if(k*k>((j*j)+(i*i)))
                    {  l=k;
                        break;
            }
        }
    }
    }
    return 0;
}

