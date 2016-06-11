#include<stdio.h>
#include<string.h>
int main()
{
    int T,i,j,c=0,k=0,l,m,n;

    scanf("%d",&T);
    for(i=0;i<T;i++)
     {
       char string[1000];
       gets(string);
       n=strlen(string);

       while(string[n-1]!=string[k]&&n!=k)
       {
           l=string[n-1];
           m=string[k];
           if(l>=m)
           {   l--;
               c=c+1;

           }
           else
           {
               printf("the above string cant be converted to palindrome\n");
               break;
           }
           n--;
           k++;

       }
       if(l==m)
       printf("%d\n",c);

     }

return 0;
}
