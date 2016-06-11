#include <iostream> 
#include<stdio.h>
#include<math.h>
 
 
#define MAX 32000
#define LMT 180
#define LEN 32000
using namespace std;
 	long long int l=1;
  long long int primes[LEN];
  long long int arr[MAX],S[MAX],num[MAX];
void sieve()
{
	for(int i=4;i<MAX;i+=2)
		arr[i]=1;
	arr[0]=1;
	arr[1]=1;
	arr[2]=0;
	 
	for(long long int i=3;i<=sqrt(MAX);i+=2)
	{
	
		if(!arr[i])
		{
			
      		for(long long int j=i*i,k=i*2; j<MAX; j+=k)
      		{
      
				arr[j]=1;
			}
		}
	}
	
	primes[0] = 2;
	for(long long int i=3;i<=MAX;i=i+2)
	{
	
		if(!arr[i])
		{
       		primes[l++] = i;
   		}
	}
 
		
}
 
 
int main()
{
	long long int a,b,j,n,i,x,count,c,check;
	int t,h;
	sieve();
/*	for(i=0;i<l;i++)
	cout<<prime[i]<<"  ";*/
 
	
		scanf("%lld%lld%lld",&a,&b,&n);
		for(i=a;i<=b;i++)
		{
			//h=i-a;
			S[i-a]=1;
			num[i-a]=i;
		}
		
		j=0;
		while( primes[j]*primes[j]<=b)         //or simply write j<l      
		{
			for(i=((((a-1)/primes[j])+1)*primes[j]);i<=b;i+=primes[j])
			{
				count=0;
				while(num[i-a]%primes[j]==0)
				{
					num[i-a]=num[i-a]/primes[j];  //cout<<"jjk";
					count++;
				}
				S[i-a]*=(count+1);
			}
			j++;
		}
		c=0;
		for(i=a;i<=b;i++)
		{
			//h=i-a;
			if(num[i-a]!=1)
			S[i-a]*=2;
			if(S[i-a]==n)
			c++;
		}
		printf("%lld\n",c);
	return 0;
}
 

