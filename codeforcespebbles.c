#include<stdio.h>
int a[100];
int main()
{
    int n,k,min=101,max=-1,i,j,t;

    scanf("%d%d",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

        max=max>a[i]?max:a[i];
        min=min<a[i]?min:a[i];
    }

    if(max-min>k)
        printf("NO");
    else
    {
        printf("YES\n");

        for(i=0;i<n;i++)
        {
            j=1;
            t=a[i];
            while(t-->0)
            {
                if(j>k)
                    j=1;
                printf("%d ",j);
                j++;
            }
            printf("\n");
        }
    }
return 0;
}
