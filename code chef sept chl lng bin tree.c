#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int T,b;
    scanf("%d",&T);
    for(b=0;b<T;b++)
    {
        int L,c=0,e,od,d,l,q,dec=0,tot,val,m=0;
        char a[100000];
        scanf("%s",a);
        q=strlen(a);
        int A[100000];
            for(d=0;d<q;d++)
            {
                if(a[d]=='l')
                A[d]=0;
                else
                A[d]=1;

            }
            for(d=q-1;d>-1;d--)
            {
                dec=dec+A[d]*pow(2,m);
                m++;
            }
            dec=dec+1;

          L=q+1;
        if((L%2)==0)
         {
                l=L/2;
                for(e=1;e<l;e++)
                    {   od=2*e-1;
                        c=c+pow(2,od);
                    }

            tot=dec+c;
            val=2*tot;
            printf("%d\n",val);
        }

        else
        {
            l=(L-1)/2;    //left above current line
            for(e=0;e<l;e++)
            {
                c=c+pow(2,l);
            }
            printf("%d",c);
            tot=dec+c;
            printf("odd,,,,,,,,%d\n",tot);

            val=2*tot-1;
            printf("%d\n",val);
        }
    }
    return 0;
}
