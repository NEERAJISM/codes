#include<stdio.h>
int main()
{
    int T,N,f,j,c,i,h;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        if(N==0)
        {printf("1\n");
        }
        else
        { h=1;
        c=0;
            for(j=N;j>0;j--)
           {
             if(c==0)
             {
                 h=h*2;
                 c=c+1;
             }
             else if(c==1)
             {
                 h=h+1;
                 c=c-1;

             }
           }
        printf("%d\n",h);
        }
    }

return 0;
}
