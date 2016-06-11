#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,a[100],n,i,c,cmax,imax,j,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		    scanf("%d",&a[i]);	
		}
		sort(a,a+n);
		
		i=0,cmax=0;imax=a[0];
		while(i<n)
		{
			b=a[i];j=1;c=0;
			while(a[i+j]==b&&i+j<=n)
			{
				c++;
				j++;
			}
			if(c>cmax)
			{
				cmax=c;
				imax=b;
			}
			i+=c+1;
		}
		printf("%d",imax);
		printf(" %d",cmax+1);
		printf("\n");
		
		
   }
   return 0;
}
   
