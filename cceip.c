#include<stdio.h>
int main()
{
	long long int n,i,k,count=0,j;
	
	scanf("%lld%lld",&n,&k);	
	
	for(i=0;i<n;i++)
	{
		scanf("%lld",&j);
		if(j%k==0)
			count++;
	}
	
	printf("%lld",count);
	return 0;
}
