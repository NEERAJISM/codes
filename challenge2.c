#include<stdio.h>
#include<math.h>
int main()
{int T,X,Y,i,j,u=1,v=0,r,s;
scanf("%d\n",&T);
for(j=0;j<T;j++)
  {scanf("%d %d\n",&X,&Y);
  if(X==0&&Y==0)
  {printf("YES\n");
   break;
     }
  for(i=0;i<pow(10,9);i++)
    {u=u+((pow(-1,i+1))*(pow(3,)));
    if(u==X)
     {r=0;
      break;
      }
    }

      for(i=0;i<pow(10,9);i++)
      {v=v+((pow(-1,i+2))*2);
      if(v==Y)
      {s=0;
      break;
      }
      }
        if(r==0&&s==0)
        printf("YES\n");
        else
        printf("NO\n");
  }
  return 0;
}
