// toeplitz matrix
#include<stdio.h>
int main()
{
    int r=5,c=5,a[100][100],i=0,j;

    for(j=0;j<c;j++)
    {
        scanf("%d",&a[i][j]);
        int s=i+1,t=j+1;
		int temp = a[i][j];

        while(t<c)
        {
            a[s][t]= temp;
        	t++;
			s++;
		}
    }

    j=0;


    for(i=1;i<r;i++)
    {
        scanf("%d",&a[i][j]);
        int s=i+1,t=j+1;
		int temp = a[i][j];
        while(s<r)
        {
            a[s][t]=temp;
			s++;
			t++;
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
return 0;
}

