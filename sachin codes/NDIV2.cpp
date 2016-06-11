#include <iostream> 
#include<stdio.h>
#include<math.h>
using namespace std;
 

#define MAX 32000
#define LMT 180
#define LEN 10000
using namespace std;
 
  int prime[LEN];
  int arr[MAX];
void sieve()
{
	 
	for(int i=3;i<=LMT;i+=2)
	{
	
		if(!arr[i])
		{
	
      		for(int j=i*i,k=i*2; j<MAX; j+=k)
      		{
      
				arr[j]=1;
			}
		}
	}
		int l=1;
	prime[0] = 2;
	for(int i=3;i<=MAX;i=i+2)
	{
	
		if(!arr[i])
		{
	
       		prime[l++] = i;
   		}
	}
 
		
}
int main()
{
	long long int a,b,j,n,i,s,x,count,c;
	sieve();
	scanf("%lld%lld%lld",&a,&b,&n);
	c=0;
	for(i=a;i<=b;i++)
	{
		x=i;j=0;s=1;
	//	long long int k=sqrt(x);
		while(prime[j]*prime[j]<=x)
		{
			count=0;
			while(x%prime[j]==0)
			{
				x=x/prime[j];
				count++;
			}
			s*=(count+1);
			if(s>n)
			break;
			j++;
		}
		if(x!=1)
		s*=2;
		if(s==n)
		c++;
	}
	printf("%lld\n",c);
	return 0;
}


