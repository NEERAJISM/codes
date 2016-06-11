#include<stdio.h>
int power(int x,int y)
{
    int t;
    if(y==0)
        return 1;
    else if(y%2>0)
        return (x*power(x,y-1));
    else
    {
        t=power(x,y/2);
        return t*t;
    }
}
int main()
{
    int t,a,p,q,b,r,s,n,m;

    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d%d%d%d",&p,&r,&q,&s);
        a=p%q;
        b=p/q;
        if(r>=s&&a==0)
            printf("divisible\n");
        else if(a!=0&&s>=r)
            printf("not divisible\n");
        else if(a==0&&s>r)
        {
            n=power(b,r);
            m=power(q,s-r);

            if(n%m==0)
                printf("divisible\n");
            else
                printf("not divisible\n");
        }
        else if(a!=0&&s<r)
        {
            n=power(p,r);
            m=power(q,s);

            if(n%m==0)
                printf("divisible\n");
            else
                printf("not divisible\n");
        }


    }

return 0;
}
