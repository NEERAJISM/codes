/* Euler's totient or phi function, f(n), is an arithmetic function that counts the totatives of n, 
 that is, the positive integers less than or equal to n that are relatively prime to n.
  Thus, if n is a positive integer, 
  then f(n) is the number of integers k in the range 1 = k = n for which the greatest common divisor gcd(n, k) = 1.
  
f (n) ={a : 1<=a<=n, gcd(a, n) = 1}

If m and n are coprime, then f (m * n) = f (m) * f (n). 
  
Euler’s totient theorem:
If n is a positive integer and a is coprime to n, then a^f (n) = 1 (mod n).

Fermat’s little theorem:
If p is a prime number, then for any integer a that is coprime to n, we have

a^p = a (mod p)

This theorem can also be stated as: If p is a prime number and a is coprime to p, then

a^(p -1) = 1 (mod p)

Fermat’s little theorem is a special case of Euler’s totient theorem when n is prime. */

#include<iostream>
#include<stdio.h>
using namespace std;

int euler_totient(int n) 
 { 
       int result = n; 
       for(int i=2;i*i <= n;i++) 
       { 
           if (n % i == 0) 
		   result -= result / i; 
		 
           while (n % i == 0)
		   {
		 	   n=n/i;    //http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=primeNumbers
		   } 
       } 
       if (n > 1)
	   result -= result / n; 
       return result; 
} 
int main()
{
	int n,ans;
	cout<<"enter the no.\n";
	cin>>n;
	ans=euler_totient(n);
	cout<<"result is = "<<ans<<endl;
	return 0;
}
