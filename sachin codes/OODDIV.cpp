#include <iostream> 
#include<stdio.h>
#include<math.h>
using namespace std;
 

#define MAX 100010
#define LMT 320
#define LEN 100000
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
	}}
 long long int divn(int n) {
	int res = 1, i, c;
	for(i=2; i*i<=n; i++) {
		if(n % i == 0) {
			c = 0;
			while(n % i == 0) {
				n /= i;
				c++;
			}
			res *= (2*c+1);
		}
	}
	if(n>1) res *= 3;
	return res;
}

int main()
{
	long long int t,a,b,B=100000,j,k,i,s,x,K,count,c,A[200000]={0};
	sieve();

K=1;
	for(i=K;i<=B*B;i=(++K)*K)
	{
		s=divn(i);

		A[K]=s;
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&k,&a,&b);
		c=0;K=sqrt(a);
		for(i=K-1;i<=b;i=(++K)*K)
		{
			if(A[K]==k)
			c++;
		}
		printf("%lld\n",c);
	}
	
	return 0;
}																													


