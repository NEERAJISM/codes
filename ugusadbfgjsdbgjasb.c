#include<stdio.h>
#include<string.h>
int main()
{
    int T,j,r,c=0,n,y,z,i,l;
    scanf("%d",&T);
    for(j=0;j<T;j++)
    {
        char a[1000];
        gets(a);
        n=strlen(a);
        i=0;
        l=n-1;
        while(i!=l)
        {c=0;
         i++;
         l--;
         y=a[i];
         z=a[l];
            if(y!=z)
            {
            r=(z>y?z-y:y-z);
            c=c+r;
            }
        }

        printf("%d\n",c);
    }
    return 0;
    }

