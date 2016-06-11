#include<stdio.h>
void STDIN();
void STDOUT(int x,int y);
int main()
{STDIN();
return 0;
}
void STDIN()
{int a,b;
 scanf("%d%d",&a,&b);
STDOUT(a,b);
return 0;
}
void STDOUT(int x,int y)
{int d;
 d=x+y;
 printf("%d",d);
return 0;
}
