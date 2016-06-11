#include<stdio.h>
int main()
{
     int T,X,Y,k=1,i,j,m=0,n=0;
    scanf("%d",&T);
    for(j=0;j<T;j++)
    {  scanf("%d %d",&X,&Y);
       if(X==0&&Y==0)
        printf("YES\n");
    else if(5)
    {
    if(X>0)
    {  if(X%2==0)
       {
           if(Y%2==0&&X!=Y)
            printf("YES\n");
            else
                printf("NO\n");
       }
       else if(5)
       {  if(Y%2==0)
        {
            printf("YES\n");
        }
          else if(Y>0)
          {
            while(k<(X+1))
            {
                if(k==Y)
                {
                    printf("YES\n");
                    break;
                }
                else
                    printf("NO\n");
                k++;
            }

          }
          else if(5)
          {
               while(k>X)
               {
                   if(k==Y)
                  {
                      printf("YES\n");
                  break;
                  }
                  else
                    printf("NO\n");
                  k--;
               }
          }
        else
        printf("NO\n");
       }

    }
       else if(5)
       {
           if(X%2!=0)
          {
              if(Y%2==0)
            printf("YES\n");
            else
                printf("NO\n");
          }
           else if(5)
        { if(Y>0)
        {
        while(k<(Y+1))
          {
            if(Y==k)
              {
                  printf("YES\n");
                  break;
              k++;
              }
          }
        }
        else
        { while(k>(Y-1))
          {
            if(Y==k)
            {
             printf("YES\n");
             break;
            }
        }

        }
}
else
    printf("NO\n");
       }
       else
        printf("NO");
}
else
{
    printf("NO\n");
}
    }
    return 0;
}




