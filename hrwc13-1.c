#include<stdio.h>
int main()
{
    long long int t,b,sum,t1,w,x,y,z;

    scanf("%lld",&t);

    while(t-->0)
    {
        scanf("%lld%lld",&b,&w);
        scanf("%lld%lld%lld",&x,&y,&z);
        t1=x>y?x-y:y-x;
        if(t1<=z)
            sum=(b*x)+(w*y);
        else
        {
            if(x>y)
                sum=(y*(b+w))+ z*b;
            else
                sum=(x*(b+w))+ z*w;
        }
        printf("%lld\n",sum);
    }
return 0;
}
