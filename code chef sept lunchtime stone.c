//stone pile max selection
#include<stdio.h>
int main()
{
    int T,N,i,j,*k,o,s=0,l,temp;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
        {
            scanf("%d\n",&N);
            int *A =(int*)malloc(N*sizeof(int));
            for(j=0;j<N;j++)
                {
                    scanf("%d\n",&A[j]);

                }
            k=&A[N-1];

            if(N%2==0)
                o=N/2;
            else
                o=(N/2)+1;

            for(j=0;j<N;j++)
                {
                       for(l=0;l<j;l++)
                        {
                            if(A[l]>A[j])
                                {
                                    temp=A[l];
                                    A[l]=A[j];
                                    A[j]=temp;

                                }
                        }
                }
                s=0;
            for(j=1;j<=o;j++)
                {
                    s=s+*k;                       //adding chefs stone
                    k=k-2;
                }
            printf("%d\n",s);
        }
return 0;
}
