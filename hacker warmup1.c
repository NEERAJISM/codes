#include<stdio.h>
int main()
{
    long long int t,n,x,temp,add;
    scanf("%lld",&t);
    while(t-->0)
    {
        add= 0;
        scanf("%lld",&n);
        temp = n;
        while(temp!=0)
        {
            x=temp%10;
            if(x!=0&&n%x==0)
                add++;

            temp =temp/10;
        }

        printf("%lld\n",add);
    }
return 0;
}

