#include<stdio.h>
int main()
{
	int n,i,j,a[100000][2],q,k,d,e,l,c,c1,flag,z;
	char b[100000];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		j=0;
		for(j=0;j<2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	scanf("%d",&q);
	
	for(i=0;i<q;i++)
	{	printf("/*/*/*/*1111\n");
		scanf("%d",&d);

		for(j=0;j<d;j++)
		{	c=0;
			scanf("%d",&e);
			printf("/*/*/*/*2222\n");
			for(k=0;k<n;k++)
			{	printf("/*/*/*/*333\n");
				if(a[k][0]<=e&&a[k][1]>=e)
				{	printf("/*/*/*/*k=%d,,,e=%d,,,,%d %d\n",k,e,a[k][0],a[k][1]);
					if(c==0)
					{
						b[c]=k;
						c++;			
					}
					else
					{
						c1=0;
						while(c1++<c)
						{	printf("/*/*/*/*4444\n");
							if(b[c1]==b[c])
							{	flag=1;
							    break;
							}
						}
						if(flag!=1)
						{
							printf("/*/*/*/*5555\n");
							flag=0;
							b[c]=k;
							z=c;
							c++;
						}
						
					}
					printf("c=%d",c);		
				}
			}
			
			
		}
				printf("%d\n",z);
	}
return 0;	
}
