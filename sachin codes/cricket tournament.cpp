#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

long long int max(long long int x, long long int y)
{ return (y > x)? y : x; }
 
long long int maxSubArraySum(long long int a[], int size)
{
   long long int max_so_far = a[0];
   int i;
   long long int curr_max = a[0];
 
   for (i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int main()
{
	int t,n,i,pmax,pmin,j;
	long long int max,min,x,a[1003],b[1003];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		
		pmin=10000;
		pmax=100000;
	b[0]=-(pmin*pmax);
	
		for(i=1;i<n;i++)
		{
			b[i]=a[i]-a[i-1];
		}
		max= maxSubArraySum(b, n);
		printf("%lld\n",max);
		
	}
	return 0;
}
