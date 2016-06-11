#include<stdio.h>
int main()
{
int z,c=0,t,n,m,op;
scanf("%d%d",&n,&m);
z=n;
t=n/m;
while(t>0)
  {
      t=n/m;
    c=c+t;
    n=t;

  }
  op=z+c;
  printf("%d\n",op);
  return 0;
}
