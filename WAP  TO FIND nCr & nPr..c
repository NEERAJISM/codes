/*TO FIND nCr & nPr*/


#include<stdio.h>
int main()
{
    char q;
    long int n,r,i,j,pr,co;

    printf("ENTER p FOR PERMUTATION or  c FOR COMBINATION  ");
    scanf("%c",&q);
    printf("ENTER THE VALUES OF n & r\n");
    scanf("%d %d",&n,&r);
     j=n-r;
    for(i=n-1;i>0;i--)
    {
        n=n*i;
    }
    if(r==0)
      {
          r=1;
      }
      else
   {
    for(i=r-1;i>0;i--)
    {
      r=r*i;
    }
   }
    for(i=j-1;i>0;i--)
    {
        j=j*i;
    }

    if(q=='p')
       {
        pr=n/r;
            printf("the permutation is %d",pr);

       }
    else if(q=='c')
       {
        co=n/(r*j);
        printf("the combinbation is %d",co);
       }
return 0;
}

