#include<stdio.h>
#include<math.h>
int a[10000000];      //initialise  value ==0
int main()
{
    int n,i,j;
    a[0]=1;
    a[1]=1;
    scanf("%d",&n);
    for(i=3;i<sqrt(n);i+=2)         //we are skipping all odd valuesmi
    {
        if(a[i]==0)
        {
            for(j=i*i;j<n;j+=i*2)
                a[j]=1;
        }
    }
    printf("2 ");
    for(i=3;i<n;i+=2)
    {
        if(a[i]==0)
            printf("%d ",i);
    }
return 0;
}
