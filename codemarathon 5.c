#include<stdio.h>
int main()
{
    int i,t,n,m,u,v;

    scanf("%d",&t);

    while(t-->0)
    {
        scanf("%d%d",&n,&m);

        for(i=0;i<m;i++)
            scanf("%d%d",&u,&v);

        printf("%d\n",n-m-1);
    }
return 0;
}
