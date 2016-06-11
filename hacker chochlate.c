#include<stdio.h>
int main()
{
   unsigned int T,d,k,op,j,c,i;
    scanf("%u",&T);
    for(i=0;i<T;i++)
    {c=1;
    op=0;
        scanf("%u",&k);
        for(j=2;j<(k+1);j++)
        {
            op=op+c;
            if((j+1)%2==0)
                c++;
        }
    printf("%u\n",op);
    }
return 0;
}
