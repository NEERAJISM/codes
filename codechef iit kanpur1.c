#include<stdio.h>
int main()
{
    int i,T,N,j,k,temp,x,y,c,d;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        int *a =(int*)malloc(N*sizeof(int));

        for(j=0;j<N;j++)
        scanf("%d",&a[j]);

        for(j=0;j<N;j++)
        {
            for(k=0;k<N;k++)
            {
                if(a[k]>a[j])
                {
                    temp=a[k];
                    a[k]=a[j];
                    a[j]=temp;
                }
            }
        }

            j=1;

            x=(a[N-1]+a[N-2])/2;

            printf("%d\n",x);
    }
return 0;
}




