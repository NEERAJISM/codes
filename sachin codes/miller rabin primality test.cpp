/*Let p be the given number which we have to test for primality. First we rewrite p-1 as (2d)*s. 
Now we pick some a in range [1,n-1] and then check whether as = 1 ( mod p ) or a(s*(2r)) = -1 ( mod p ).
 If both of them fail, then p is definitely composite. Otherwise p is probably prime. 
 We can choose another a and repeat the same test.
  We can stop after some fixed number of iterations and claim that either p is definitely composite, 
  or it is probably prime.

A small procedure realizing the above algorithm is given below:

Miller-Rabin primality test, iteration signifies the accuracy of the test */
#include<bits/stdc++.h>
using namespace std;


long long mulmod(long long int a,long long int b,long long int c)
{
	long long int x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x+y)%c;
		}
		y=(y+y)%c;
		b=b/2;
	}
	return x%c;
}

long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y)%c;      //  or call  mulmod(x,y,c);
		}
		y=(y*y)%c;          //  or call  mulmod(y,y,c);
		b=b/2;
	}
	return x%c;
}



bool miller_rabin(long long p,int iteration)
{
    if(p<2)
	{
        return false;
    }
    if(p!=2 && p%2==0)
	{
        return false;
    }
    long long s=p-1;
    while(s%2==0)
	{
        s/=2;
    }
    for(int i=0;i<iteration;i++)
	{
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modular_exponentiation(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1)
		{
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0)
		{
            return false;
        }
    }
    return true;
}
int main()
{
	long long int n;
	bool ans;
	cout<<"enter the no. to check\n";
	cin>>n;
	ans=miller_rabin(n,50);
	cout<<"answer is = "<<ans<<endl;
	return 0;
}
