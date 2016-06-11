#include<stdio.h>
int main()
{
    long int a,b,sum,temp,n,t;
    scanf("%ld",&t);

    while(t>0)
    {
        sum=2;
        temp=0;
        a=1;
        b=2;
        scanf("%ld",&n);

        while(temp<n)
        {
            temp=a+b;
            if(temp%2==0&&temp<n)
                sum=sum+temp;

            a=b;
            b=temp;
        }
    t--;
    printf("%ld\n",sum);
    }
return 0;
}
