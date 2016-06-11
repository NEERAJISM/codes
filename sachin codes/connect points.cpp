#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,x,y,i; 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			
		}
		if(n<=4)
		{
			x=n*(n-1);
			x=x/2;
			
			
			
			if(m==x)
			{
				printf("1\n");
			}
			else
			printf("0\n");
		}
		else if(n>=5)
		{
			y=3*n-6;
			
			if(m==y)
			printf("1\n");
			else
			printf("0\n");
		}
		
	}
	return 0;
} 
