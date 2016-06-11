#include<stdio.h>
#include<stdlib.h>
int main()
{
    long int n,t,i,j,temp,count=1,b[100000];
    scanf("%d",&n);

    int* a =(int*)malloc(sizeof(int));

    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }

    j=0;
    printf("%d\n",n);
    t=n;
    while(j<t&&n>=1)
    {
        if(a[j]==a[j+1])
        {    count++;
             j++;
        }
        else
        {
            n=n-count;
            if(n==0)
            break;
            printf("%d\n",n);
            count=1;
            j++;
        }
    }

return 0;
}

