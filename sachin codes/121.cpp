#include<bits/stdc++.h>
using namespace std;
int t;


int main()
{
	int n,a[55],b[55],sum,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		
		sum=0;
		for(i=0;i<=50;i++)
			b[i]=0;
		scanf("%d",&n);
		int flag=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			if(a[i]>=n)
			flag=1;
		}
		if(sum!=n||flag==1)
		{
			printf("-1\n");
			
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				if(a[i]!=0)
				{
					for(k=i+1;k<=n && a[i]!=0;k++)
					{
						if(k!=i && a[k]!=0 && b[k]==0)
							{
								b[k]=i;a[i]--;
							}
					}					
					
				}
			
			}
			
			for(i=1;i<=n;i++)
			{
				if(a[i]!=0)
				{
					for(k=1;k<=n && a[i]!=0;k++)
					{
						if(k!=i && a[k]!=0 && b[k]==0)
							{
								b[k]=i;a[i]--;
							}
					}					
					
				}
			
			}
			
			for(i=1;i<=n;i++)
			{	if(a[i]!=0)
				{
					for(k=1;k<=n && a[i]!=0;k++)
					if(b[k]==0 && k!=i)
					{
						b[k]=i;a[i]--;
					}
				}
			}
			for(i=1;i<=n;i++)
			printf("%d ",b[i]);
			printf("\n");
		}
		
	}
	return 0;
}
