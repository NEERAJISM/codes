#include<stdio.h>
int main()
{
int c=0,t,n,m,op;
scanf("%d%d",&n,&m);
z=n;
t=n/m;
while(t>0)
  {
    c=c+n/m;
    n=n%m;
    t=n/m;
  }
  op=z+c;
  printf("%d\n",op);
  return 0;
}
