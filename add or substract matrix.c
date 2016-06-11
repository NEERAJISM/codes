/*TO ADD OR SUBSTRACT TWO MATRIX*/
#include<stdio.h>
int main()
{
    int r,c,i,j;
    char p;
    printf("enter the no. of row and column of matrices");
    scanf("%d %d",&r,&c);
    int a[r][c],b[r][c],x[r][c];
    printf("enter the matrix 'a' ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the matrix b");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("enter 'a' for addition or 's' for substraction\n");

    scanf("%c",&p);

    if(p=='a')
    {printf("the summation of the matrix is \n");
      for(i=0;i<r;i++)
    {printf("\n");
        for(j=0;j<c;j++)
        {
            x[i][j]=a[i][j]+b[i][j];
            printf("%d ",x[i][j]);
        }
    }
    }
    else if(p=='s')
    {printf("the substraction of the matrix is \n");
      for(i=0;i<r;i++)
    {printf("\n");
        for(j=0;j<c;j++)
        {
            x[i][j]=a[i][j]-b[i][j];
            printf("%d ",x[i][j]);
        }
    }
    }
    return 0;
}
