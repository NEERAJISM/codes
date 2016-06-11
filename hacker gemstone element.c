#include<stdio.h>
#include<string.h>
int main()
{
    int d,N,i,z,j,k=0,c,q=0,l=0,g,x,p;
    scanf("%d",&N);
    char a[100][100],b[100];
    for(i=0;i<N;i++)
     {
         scanf("%s",a[i]);
     }

    while(a[0][k]!='\0')
    {
        c=0;
        g=0;
        for(z=0;z<l;z++)
        {
            if(b[z]==a[0][k])
            {
                g=1;
                break;
            }
        }
         if(g!=1)
         {  i=1;
            c=0;
            while(i<N)
            {    p=0;
                 j=0;
                while(a[i][j]!='\0')
                {
                    if(a[0][k]==a[i][j])
                    {
                        c++;
                        p++;
                        i++;
                        break;
                    }

                    j++;
                }
                if(p==0)
                break;

            }

        }
       if(c==N-1)
        {
            q=q+1;
            b[l]=a[0][k];
            l++;
        }
    k++;
    }
    printf("%d\n",q);
return 0;
}
