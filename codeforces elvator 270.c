#include<stdio.h>

int main()
{
    int c,n,i,x,k,j,l,left,t;
    scanf("%d%d",&n,&k);
    int *a =(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);


            for(j=0;j<n;j++)
                {
                       for(l=0;l<j;l++)
                        {
                            if(a[l]>a[j])
                                {
                                    temp=a[l];
                                    a[l]=a[j];
                                    a[j]=temp;

                                }
                        }
                }
    if(k>=n)
    {
        t=2*(a[n-1]-1);
        printf("%d",t);
        return 0;
    }
    else
    {
        i=0;
        left=n;
        while(left!=0)
        {   c=1;
            while(a[i]==a[i+1]&&c<=k&&i<n)
                c++;


        t=2*(a[i]-1);
        left=left-c;
        i++;

        }








