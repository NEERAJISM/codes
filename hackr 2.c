#include<stdio.h>
int main()
 {int i,N,m,T,j,z,op=0;
 scanf("%d",&T);
 for(j=0;j<T;j++)
 {scanf("%d%d",&N,&m);
 op=0;
 for(i=1;i<(N+1);i++)
 {z=i%m;
 op=op+z;

 }
 printf("%d\n",op);

 }
 return 0;
 }
