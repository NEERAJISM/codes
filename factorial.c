/*factorial*/

#include<stdio.h>
int main()
{
int n,i;
printf("enter the number");
scanf("%d",&n);

if(n==0)
printf("the factorial of n is 1");

else
{for(i=n-1;i>0;i--)
{n=n*i;
}
printf("the factorial of n is %d",n);
}
return 0;
}
