/*highway lane*/
#include<stdio.h>
int main()
{
    int N,a,T,i,j,op,k,z;
    scanf("%d%d",&N,&T);
    int width[N];
    for(a=0;a<N;a++)
    {
        scanf("%d",&width[a]);
    }
      for(a=0;a<T;a++)
      {
        scanf("%d%d",&i,&j);
        k=j-i+1;
        int temp[k],b,c,d,e;
        for(b=0;b<k;b++)
          {temp[b]=width[i];
           i=i+1;
          }
          for(c=0;c<k;c++)
          {
              for(d=c;d<k;d++)
              {
                  if(temp[d]<temp[c])
                  {
                      e=temp[c];
                      temp[c]=temp[d];
                      temp[d]=e;
                      break;
                  }
              }
          }
          printf("%d\n",temp[0]);
      }
return 0;
}
