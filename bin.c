#include<stdio.h>
int main()
{int a,i;
scanf("%d",&a);
int w[a+1];
for(i=0;i<a;i++)
{
    scanf("%d",&w[i]);
    printf("%d",w[i]);
}

return 0;}
