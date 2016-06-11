#include<stdio.h>
int main()
{int a[60],i,j,T,n,k,r;
scanf("%d\n",&T);
for(j=0;j<T;j++)
   {scanf("%d %d\n",&n,&k);
    r=0;
    for(i=0;i<n;i++)
     {
      scanf("%d\n",&a[i]);
     if((a[i]%2)==0)
      r=r+1;
     }
      if(r==n&&k==0)
      printf("NO\n");
      else if(r>=k)
      printf("YES\n");
      else
      printf("NO\n");

   }
      return 0;
}
