/*matrix multiplication using static array*/
#include<stdio.h>
int main()
{
    int r1,c1,r2,c2,i,j,k;
    printf("enter the no. of rows and columns of first and second matrix");
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    if(c1!=r2)
        printf("the multiplication is not possible");
    else
    {int a[10][10],b[10][10],c[10][10];
        printf("enter the first matrix");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        printf("enter the second matrix");
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }

        for(i=0;i<r1;i++)
        {
            printf("\n");
            for(j=0;j<c2;j++)
            { c[i][j]=0;
            printf("\n");
                for(k=0;k<c1;k++)
                {c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }

    }
    for(i=0;i<r1;i++)
    {printf("\n");
        for(j=0;j<c2;j++)
            printf("%d ",c[i][j]);
    }
    }
    return 0;
}
