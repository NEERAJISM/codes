#include<stdio.h>
long long int rm,gm,bm,grt;
void arrange();
int main()
{
    int T;
    scanf("%d",&T);
    while(T-->0)
    {
        long long int R,G,B,M,i,r,g,b;
        scanf("%lld%lld%lld%lld",&R,&G,&B,&M);

        rm=0;
        for(i=1;i<=R;i++)
        {
            scanf("%lld",&r);

            if(r>rm)
                rm=r;
        }
        gm=0;
        for(i=1;i<=G;i++)
        {
            scanf("%lld",&g);

            if(g>gm)
                gm=g;
        }
        bm=0;
        for(i=1;i<=B;i++)
        {
            scanf("%lld",&b);

            if(b>bm)
                bm=b;
        }

        while(M-->0)
        {
            arrange();
        }

            if(gm>grt)
                grt=gm;
            else if(bm>grt)
                grt=bm;
            else if(rm>grt)
                grt=rm;

        printf("%lld\n",grt);
    }
return 0;
}

void arrange()
{
    grt=rm;

    if(gm>grt)
        grt=gm;
    if(bm>grt)
        grt=bm;

    if(grt==rm)
        rm=rm/2;
    else if(grt==gm)
        gm=gm/2;
    else
        bm=bm/2;

        grt=grt/2;
}
