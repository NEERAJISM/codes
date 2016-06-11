#include<iostream>
#include<stdio.h>
using namespace std;

int gcd(int a,int b)
	{
		if(b==0)
		return a;
		else
		gcd(b,a%b);
	}
	
int main()
{
	int t,n,a[51],i,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	    
	    c=gcd(a[0],a[1]);
	    for(i=2;i<n;i++)
	    {
	    	c=gcd(c,a[i]);
	    }
	    for(i=0;i<n;i++)
	    {
	    	a[i]=a[i]/c;
	    }
	    for(i=0;i<n;i++)
	    {
	    	printf("%d",a[i]);
	    	printf(" ");
	    }
	    printf("\n");
	}
	return 0;
	

}
