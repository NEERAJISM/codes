#include<stdio.h>
int main()
{
    int T,j;
    scanf("%d\n",&T);
    for(j=0;j<T;j++)
    {
        int y,z,l,i=0,c=0,r=0,n;
        char a[1000];
        gets(a);
        n=strlen(a);
        l=n-1;
        while(i<l)
        {
          y=a[i];
          z=a[l];
          if(y!=z)
          {
              if(z>y)
                r=z-y;
              else
                r=y-z;
          c=c+r;
          }
          i++;
          l--;
        }
        printf("%d\n",c);

    }
return 0;
}
