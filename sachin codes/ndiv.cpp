#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <vector>
#define ll long long
using namespace std;
int k=0,primes[100000];

void sieve_atkins(ll int n)
{
    vector<bool> is_prime(n + 1);
    is_prime[2] = true;
    is_prime[3] = true;
    for (ll int i = 5; i <= n; i++)
    {
        is_prime[i] = false;
    }
    ll int lim = ceil(sqrt(n));
    for (ll int x = 1; x <= lim; x++)
    {
        for (ll int y = 1; y <= lim; y++)
        {
            ll int num = (4 * x * x + y * y);
            if (num <= n && (num % 12 == 1 || num % 12 == 5))
            {
                is_prime[num] = true;
            }
            num = (3 * x * x + y * y);
            if (num <= n && (num % 12 == 7))
            {
                is_prime[num] = true;
            }
 
            if (x > y)
            {
                num = (3 * x * x - y * y);
                if (num <= n && (num % 12 == 11))
                {
                    is_prime[num] = true;
                }
            }
        }
    }
    for (ll int i = 5; i <= lim; i++)
    {
        if (is_prime[i])
        {
            for (ll int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
 
    for (ll int i = 2; i <= n; i++)
    {
         if (is_prime[i])
         {
             primes[k]=i;
             k++;
         }
    }
}
 
int main()
{
	int n,j,l,c,count,ans,x,pos;
	
	long long int a,b,i;
	sieve_atkins(32000);
	scanf("%lld%lld%d",&a,&b,&n);
	
//	for(i=0;i<k;i++)
//	cout<<primes[i]<<"  ";
    c=0;
	for(i=a;i<=b;i++)
	{
		
		ans=1;
	    int temp=i;
	  //cout<<l<<"  "<<j<<endl;
		for(x=0;x<k && temp>1 ;x++)
		{
			count=0;
			 
			
			while(temp%primes[x]==0)
			{
				temp=temp/primes[x];
				count++;
			}
			ans*=(count+1);
		}
		                                 
	    if(temp!=1&&i!=1)
	    ans*=2;
	
		if(ans==n)
		c++;
	 // cout<<i<<" "<<ans<<" "<<c<<endl<<endl;
	}
	printf("%d",c);
	return 0;
}

