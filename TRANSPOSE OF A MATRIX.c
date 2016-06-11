/*TRANSPOSE OF A MATRIX*/
#include<stdio.h>
int main()
{
    int a[10][10],b[10][10],i,j,r1,c1;
    printf("enter the no. rows and columns of matrix");
    scanf("%d %d",&r1,&c1);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("the given matrix is");
    for(i=0;i<r1;i++)
    {
        printf("\n");
        for(j=0;j<c1;j++)
        {
            printf("%d ",a[i][j]);
        }
    }
    printf("\n");

    /*transpose*/
    printf("the transpose is\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
            b[i][j]=a[j][i];
    }
    printf("\n");
    for(i=0;i<c1;i++)
    {printf("\n");
        for(j=0;j<r1;j++)
         printf("%d ",b[i][j]);
    }
return 0;
}

