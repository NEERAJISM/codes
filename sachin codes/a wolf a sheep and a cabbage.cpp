#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,m,i,j,x,y,c,flag,x1,x2,y1,y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(m>2)
		{
			for(i=0;i<m;i++)
			scanf("%d%d",&x,&y);
			printf("NO\n");
		}
		else if(m<2)
		{
			for(i=0;i<m;i++)
			scanf("%d%d",&x,&y);
			printf("YES\n");
		}
		else if(m==2)
		{
		
				scanf("%d%d",&x1,&y1);
				scanf("%d%d",&x2,&y2);
				if(x1!=x2&&x1!=y2&&y1!=x2&&y1!=y2)
				printf("NO\n");
				else
				printf("YES\n");
			
        }
		

		
	   
	}
	return 0;
}
