#include<stdio.h>
int main()
{
    int t,n,l,r,q,x,y,a[100000],i,t2,val,r1;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d%d",&n,&q);

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        while(q-->0)
        {
            scanf("%d%d",&l,&r);
            l--;
            r--;
            t2=0;
            x=a[0];
            y=a[1];
            while(y!=0)
            {
                r1=x%y;
                x=y;
                y=r1;
            }
            val=x;
            if(l==0)
            {
                t2=r+3;

            x=a[r+1];
            y=a[r+2];
            while(y!=0)
            {
                r1=x%y;
                x=y;
                y=r1;
            }
            val=x;
            }
            else if(l==1)
            {
                t2=r+2;

            x=a[0];
            y=a[r+1];
            while(y!=0)
                {
                    r1=x%y;
                    x=y;
                    y=r1;
                }
                val=x;
            }

            if(n-(r-l+1)==1)
            {
                if(l!=0)
                    val=a[0];
                else
                    val=a[n-1];
            }
            else
            {
                for(i=t2;i<n;i++)
                {
                    if(i<l||i>r)
                    {
                        x=val;
                        y=a[i];
                        while(y!=0)
                        {
                            r1=x%y;
                            x=y;
                            y=r1;
                        }
                        val=x;
                    }
                    else
                        t2=r+1;
                }
            }
            printf("%d\n",val);
        }
    }
return 0;
}
