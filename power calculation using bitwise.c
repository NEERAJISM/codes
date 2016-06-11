#include<stdio.h>

int main()
{
    int a,b,temp,result=1;

    scanf("%d%d",&a,&b);
    temp=a;
    while(b)
    {
        if(b&1)
            result= result*temp;

        temp=temp*temp;
        b=b/2;
    }

    printf("%d ",result);
    return 0;
}
