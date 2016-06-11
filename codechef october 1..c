#include<stdio.h>
int main()
{
    int T,N,M,i=0,j,gt,sum,A;
    scanf("%d",&T);
    while(i++<T)
    {
        scanf("%d%d",&N,&M);
        sum=0;
        gt=0;
        for(j=0;j<N;j++)
        {
            scanf("%d",&A);
            sum=sum+A;
        }
        if(((sum+M)%N)==0&&((sum+M)/N)>=gt)
            printf("Yes\n");
        else
            printf("No\n");

    }
return 0;
}
