#include<stdio.h>
int ptr(int*,int*);
int main()
{
    int a,b,*j,*k,sum;
    scanf("%d%d",&a,&b);
    j=&a;
    k=&b;
    sum=ptr(j,k);
    printf("sum= %d",sum);
    return 0;
}

    int ptr(int *x,int *y)
    {
        int d;
        d=*x+*y;
        return(d);
    }
