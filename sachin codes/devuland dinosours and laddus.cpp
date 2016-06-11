#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int a[1000000];
int main()
{
	int t,n,i,j;
	long long int c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		c=0;
		for(i=0;i<n;i++)
		{
		    j=1;
			while(a[i]!=0)
		    {
				if((a[i]*a[i+j])<0)
				{
					if(abs(a[i])<abs(a[i+j]))
					{
						a[i+j]=a[i+j]+a[i];
					    c+=(j*abs(a[i]));
						a[i]=0;
					}
					else if(abs(a[i])>=abs(a[i+j]))
					{
						a[i]=a[i]+a[i+j];
						c+=(j*abs(a[i+j]));
						a[i+j]=0;
					}
				} 
				j++; 
		    }
			
		
			
		}
		printf("%lld\n",c);
	}
	return 0;
}
