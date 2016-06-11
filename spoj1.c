#include<stdio.h>
int j,a[10000000],i;
int main()
{
    i=0;
    while(1)
    {
        scanf("%d",&a[i]);
        if(a[i]==42)
            break;
        i++;
    }

    for(j=0;j<i;j++)
        printf("%d\n",a[j]);
    return 0;
}
