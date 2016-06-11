#include<stdio.h>
int main()
{
   long int N,M,d,i,k,j,x;
    char R[1];
    scanf("%ld%ld",&N,&M);
    long int *A =(long int*)malloc(N*sizeof(long int));
    for(i=0;i<N;i++)
    {
        scanf("%ld",&A[i]);
    }

    for(i=0;i<M;i++)
        {
           scanf("%s%ld",&R,&d);
           if(R[0]=='R')
           {  d=d-1;
              printf("%ld\n",A[d]);
           }

           else if(R[0]=='C')
           {
              d=N-d;
              for(j=0;j<d;j++)
              {

                  x=A[N-1];
                  for(k=N-2;k>-1;k--)
                  {
                    A[k+1]=A[k];
                  }
                  A[0]=x;

              }
           }
           else if(R[0]=='A')
           {
              for(j=0;j<d;j++)
              {
                  x=A[N-1];
                  for(k=N-2;k>-1;k--)
                  {
                    A[k+1]=A[k];
                  }
                  A[0]=x;

              }
           }

        }

return 0;

}
