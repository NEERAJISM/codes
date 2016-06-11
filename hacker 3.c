#include<stdio.h>
int main()
{int N,i,j,a[1000],b,c,p;
scanf("%d",&N);
for(i=0;i<N;i++)
{
    scanf("%d",&a[i]);
}
  for(i=0;i<N;i++)
  {for(j=i;j<N;j++)
  {
      if(a[i]>a[j])
      {
        b=a[i];
        a[i]=a[j];
        a[j]=b;
        break;
      }
  }
  }
      for(j=N;j>0;j--)
      {p=a[j]%2;
          if(p==0)
         {
          for(i=0;i<N;i++)
         {  if(a[j]==a[i]*2)
            {
                c=i+(N-j-1);
             break;
            }
          }
          }
          if(a[j]==a[i]*2)
          break;
      }
      printf("%d\n",c);

return 0;
}


